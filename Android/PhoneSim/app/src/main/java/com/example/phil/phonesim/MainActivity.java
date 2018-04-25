package com.example.phil.phonesim;

import android.Manifest;
import android.app.AlertDialog;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.ContentResolver;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.os.Parcelable;
import android.os.PersistableBundle;
import android.provider.ContactsContract;
import android.provider.Settings;
import android.support.annotation.Nullable;
import android.support.design.widget.FloatingActionButton;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v4.content.LocalBroadcastManager;
import android.support.v7.app.AppCompatActivity;
import android.telephony.PhoneNumberUtils;
import android.telephony.SmsManager;
import android.text.TextUtils;

import android.app.ActivityManager;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.util.Patterns;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import org.json.JSONObject;
import org.parceler.Parcels;


//SPRINT 3
public class MainActivity extends AppCompatActivity {
    //Used for ConnService
    //Returns CTX
    Context ctx;
    public volatile boolean isConnected = false;
    private static boolean registered = false;

    //alert dialog prompting user to enable notification listening permissions for our app
    private AlertDialog enableNotificationListenerAlertDialog;
    private static final int MY_PERMISSIONS_REQUEST_READ_CONTACTS = 11;

    //sys codes used by the alert dialog
    private static final String ENABLED_NOTIFICATION_LISTENERS = "enabled_notification_listeners";
    private static final String ACTION_NOTIFICATION_LISTENER_SETTINGS = "android.settings.ACTION_NOTIFICATION_LISTENER_SETTINGS";

    //connects to web service
    FloatingActionButton connectButton;

    //disconnects to web service
    FloatingActionButton disconnectButton;

    //sends a test text
    FloatingActionButton sendButton;
    // Edit Text IP
    EditText ipText;
    EditText portText;

    public Context getCtx() {
        return ctx;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ctx = this;
        setContentView(R.layout.activity_main);

        // Here, thisActivity is the current activity
        if (ContextCompat.checkSelfPermission(ctx,
                Manifest.permission.READ_CONTACTS)
                != PackageManager.PERMISSION_GRANTED ||
                ContextCompat.checkSelfPermission(ctx,
                        Manifest.permission.SEND_SMS)
                        != PackageManager.PERMISSION_GRANTED) {

            // Permission is not granted
            // Should we show an explanation?
            if (ActivityCompat.shouldShowRequestPermissionRationale(MainActivity.this,
                    Manifest.permission.READ_CONTACTS)) {

                // Show an explanation to the user *asynchronously* -- don't block
                // this thread waiting for the user's response! After the user
                // sees the explanation, try again to request the permission.

            } else {

                // No explanation needed; request the permission
                ActivityCompat.requestPermissions(MainActivity.this,
                        new String[]{Manifest.permission.READ_CONTACTS,
                                Manifest.permission.SEND_SMS},
                        MY_PERMISSIONS_REQUEST_READ_CONTACTS);

                // MY_PERMISSIONS_REQUEST_READ_CONTACTS is an
                // app-defined int constant. The callback method gets the
                // result of the request.
            }
        } else {
            // Permission has already been granted
        }

        // If the user did not turn the notification listener service on we prompt him to do so
        //I have this ask every time for debugging reasons... for some if you are using a personal
        //android device instead of the VM, your phone may need to be restarted to get the notification
        //listener service working again when demoing the app. This apparantly shouldn't happen with the
        //APK version, but look out for issues

        if(!isNotificationServiceEnabled()){
            enableNotificationListenerAlertDialog = buildNotificationServiceAlertDialog();
            enableNotificationListenerAlertDialog.show();
        }

        //connect button
        connectButton = findViewById(R.id.connect_button);
        connectButton.setOnClickListener(v -> {
            //calls server method to connect to socket
            if(ipText.getText().toString().equals("")){
                ipText.setText("192.168.88.234");
                portText.setText("1337");
            }
            ConnService.connect(getCtx(),
                    ipText.getText().toString(),
                    portText.getText().toString());
            connectButton.setEnabled(false);
            disconnectButton.setEnabled(true);
        });

        //disconnect button
        disconnectButton = findViewById(R.id.disconnect_button);
        disconnectButton.setOnClickListener(v -> {
            //calls server method to disconnect from socket
            ConnService.disconnect(getCtx());
            connectButton.setEnabled(true);
            disconnectButton.setEnabled(false);
        });

        //this is just a test button so you can ensure your destination program is working correctly
        //real code to send texts will be in NotificationListenerExampleService
        //explanations of what is happening is also in NotificationListenerExampleService
//        sendButton = findViewById(R.id.send_button);
//        sendButton.setOnClickListener(v -> {
//            Log.i("CLICKED", "you clicked send");
//            //sends a test notification for now
//            ParcelableNotification n = new ParcelableNotification("package", "tick", "title",
//                    "TTest String", "69");
//            Parcelable parcN = Parcels.wrap(n);
//            ConnService.sendNotification(getCtx(), parcN);
//
//        });

        ipText = findViewById(R.id.ipText);
        portText = findViewById(R.id.portText);
        isNotificationServiceEnabled();
    }

    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           String permissions[], int[] grantResults) {
        switch (requestCode) {
            case MY_PERMISSIONS_REQUEST_READ_CONTACTS: {
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

                    // permission was granted, yay! Do the
                    // contacts-related task you need to do.

                } else {

                    // permission denied, boo! Disable the
                    // functionality that depends on this permission.
                }
                return;
            }

            // other 'case' lines to check for other
            // permissions this app might request.
        }
    }

    private void SendSMSMessage(String sender, String Message){
        String contactNumber = "";
        if(Patterns.PHONE.matcher(sender).matches()){
            contactNumber = sender;
        }else {
            //
            //  Find contact based on name.
            ContentResolver cr = getContentResolver();
            Cursor cursor = cr.query(ContactsContract.Contacts.CONTENT_URI, null,

                    "DISPLAY_NAME = '" + sender + "'", null, null);
            if (cursor.moveToFirst()) {
                String contactId =
                        cursor.getString(cursor.getColumnIndex(ContactsContract.Contacts._ID));
                //
                //  Get all phone numbers.
                //
                Cursor phones = cr.query(ContactsContract.CommonDataKinds.Phone.CONTENT_URI, null,
                        ContactsContract.CommonDataKinds.Phone.CONTACT_ID + " = " + contactId, null, null);
                if (phones.getCount() > 1) {
                    while (phones.moveToNext()) {
                        String number = phones.getString(phones.getColumnIndex(ContactsContract.CommonDataKinds.Phone.NUMBER));
                        int type = phones.getInt(phones.getColumnIndex(ContactsContract.CommonDataKinds.Phone.TYPE));
                        switch (type) {
                            case ContactsContract.CommonDataKinds.Phone.TYPE_HOME:
                                // do something with the Home number here...
                                break;
                            case ContactsContract.CommonDataKinds.Phone.TYPE_MOBILE:
                                // do something with the Mobile number here...
                                break;
                            case ContactsContract.CommonDataKinds.Phone.TYPE_WORK:
                                // do something with the Work number here...
                                break;
                        }
                    }
                } else {
                    phones.moveToFirst();
                    contactNumber = phones.getString(phones.getColumnIndex(ContactsContract.CommonDataKinds.Phone.NUMBER));
                }
                phones.close();
            }
            cursor.close();
        }
        if(contactNumber.equals("")){
            Log.i("Main", "DoSTUFF: PROBELM SEARCHING CONTACTS");
        }else{
            SmsManager sm = SmsManager.getDefault();
            sm.sendTextMessage(contactNumber,null,Message,null,null);
        }
    }

    @Override
    protected void onStart() {
        super.onStart();
        registerIntentFilter();
    }

    /**
     * Is ParcelableNotification Service Enabled.
     * Verifies if the notification listener service is enabled.
     * Got it from: https://github.com/kpbird/NotificationListenerService-Example/blob/master/NLSExample/src/main/java/com/kpbird/nlsexample/NLService.java
     * @return True if eanbled, false otherwise.
     */
    private boolean isNotificationServiceEnabled(){
        String pkgName = getPackageName();
        final String flat = Settings.Secure.getString(getContentResolver(),
                ENABLED_NOTIFICATION_LISTENERS);
        if (!TextUtils.isEmpty(flat)) {
            final String[] names = flat.split(":");
            for (int i = 0; i < names.length; i++) {
                final ComponentName cn = ComponentName.unflattenFromString(names[i]);
                if (cn != null) {
                    if (TextUtils.equals(pkgName, cn.getPackageName())) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    /**
     * Build ParcelableNotification Listener Alert Dialog.
     * Builds the alert dialog that pops up if the user has not turned
     * the ParcelableNotification Listener Service on yet.
     * @return An alert dialog which leads to the notification enabling screen
     */
    private AlertDialog buildNotificationServiceAlertDialog(){
        AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(this);
        alertDialogBuilder.setTitle("HELLO");
        alertDialogBuilder.setMessage("Please enable the notification service listener permission.");
        alertDialogBuilder.setPositiveButton("YES",
                (dialog, id) -> startActivity(new Intent(ACTION_NOTIFICATION_LISTENER_SETTINGS)));
        alertDialogBuilder.setNegativeButton("NO",
                (dialog, id) -> {
                    // If you choose to not enable the notification listener
                    // the app. will not work as expected
                });
        return(alertDialogBuilder.create());
    }

    /**
    * This broadcast receiver receives messages from ConnService via IntentFilters
    * Only used for testing purposes right now i.e. toasts to show connected/message sent
    *
    * You may use this later for something else, just needs more intent filters registered
    * */
    private BroadcastReceiver statusReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            if(intent.getAction().equals(ConnService.BROADCAST_NOTIFICATION_SENT)){
                Toast.makeText(MainActivity.this, "Message Sent", Toast.LENGTH_SHORT).show();
            }
            else if(intent.getAction().equals(ConnService.BROADCAST_CONNECTED)){
                //Toast.makeText(MainActivity.this, "Connected", Toast.LENGTH_SHORT).show();
                Log.d("BroadCastB","Broadcast Test");
                isConnected = true;
            }
            else if(intent.getAction().equals(ConnService.BROADCAST_DISCONNECTED)){
                Toast.makeText(MainActivity.this, "Disconnected", Toast.LENGTH_SHORT).show();
            } else if(intent.getAction().equals(ConnService.BROADCAST_TEST)){
                Log.d("BroadCastC","Broadcast Test");
                String str = intent.getStringExtra("Message");
                if(str.length()> 0){
                    if(str.equals("404 OK")){
                        isConnected = true;
                    }else
                    {
                        try {
                            JSONObject myMessage = new JSONObject(str);
                            String who = myMessage.getString("who");
                            String toSend = myMessage.getString("message");
                            SendSMSMessage(who,toSend);
                        } catch (Throwable t){
                            Log.e("Json", "Could not parse json");
                        }
                    }
                }
            }
        }
    };

    protected void registerIntentFilter(){
        if(!registered) {
            //filter for connected
            //the certain intent to listen for, ignores all others
            IntentFilter connectedFilter;
            //broadcast status code sent through an intent from ConnService
            connectedFilter = new IntentFilter(ConnService.BROADCAST_CONNECTED);
            //registering receiver to start listening for this intent
            LocalBroadcastManager.getInstance(this).registerReceiver
                    (statusReceiver, connectedFilter);

            IntentFilter disconnectedFilter;
            //broadcast status code sent through an intent from ConnService
            disconnectedFilter = new IntentFilter(ConnService.BROADCAST_DISCONNECTED);
            //registering receiver to start listening for this intent
            LocalBroadcastManager.getInstance(this).registerReceiver
                    (statusReceiver, disconnectedFilter);

            //filter for notification sent
            IntentFilter notificationSentFilter;
            //broadcast status code sent through an intent from ConnService
            notificationSentFilter = new IntentFilter(ConnService.BROADCAST_NOTIFICATION_SENT);
            //registering receiver to start listening for this intent
            LocalBroadcastManager.getInstance(this).registerReceiver
                    (statusReceiver, notificationSentFilter);

            //testing
            //filter for notification sent
            IntentFilter notificationTestFilter;
            //broadcast status code sent through an intent from ConnService
            notificationTestFilter = new IntentFilter(ConnService.BROADCAST_TEST);
            //registering receiver to start listening for this intent
            LocalBroadcastManager.getInstance(this).registerReceiver
                    (statusReceiver, notificationTestFilter);
            registered = true;
        }
    }
}