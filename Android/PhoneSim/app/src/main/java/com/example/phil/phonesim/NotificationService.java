package com.example.phil.phonesim;

import android.app.Notification;
import android.app.PendingIntent;
import android.app.RemoteInput;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.Uri;
import android.os.Bundle;
import android.os.Parcelable;
import android.service.notification.NotificationListenerService;
import android.service.notification.StatusBarNotification;
import android.support.v4.content.LocalBroadcastManager;
import android.util.Log;
import android.util.SparseArray;


import com.google.gson.Gson;

import org.parceler.Parcels;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class NotificationService extends NotificationListenerService {

    private List<String> myList = Arrays.asList(
            "com.google.android.talk",
            "com.android.mms",
            "com.google.android.apps.messaging",
            "com.facebook.orca"
    );

    @Override
    public void onNotificationPosted(StatusBarNotification sbn) {

        Log.i("NOTI_FOUND", sbn.getPackageName());
        if (checkValidNotification(sbn.getPackageName(),sbn.getKey())){

            String pack = sbn.getPackageName();
            String ticker = "";
            if (sbn.getNotification().tickerText != null) {
                ticker = sbn.getNotification().tickerText.toString();
            }
            Bundle extras = sbn.getNotification().extras;
            String title = extras.getString("android.title");
            if(title.contains("new message")){
                return;
            }
            String text = extras.getCharSequence("android.text").toString();
            String nKey = String.valueOf(sbn.getId());
            //just logs in Logcat for debugging
            //package is what type of notification it is
            Log.i("Package", pack);

            //ticker is what it actually says in the status bar
            //for example Zack Hern: Hey whats up broham!?
            Log.i("Ticker", ticker);
            //title in a text message format would be the contact or number of sender
            Log.i("Title", title);
            //text in a text message format would be the actual body of the text
            Log.i("Text", text);
            /////////////////////////////////////////////////////////
            //this creates a new ParcelableNotification from the given notification components
            //and then wraps it to become a Parcelable object in order for the data to be passed
            //using Intents.
            ParcelableNotification toWrap = new ParcelableNotification(pack, ticker, title, text,nKey);
            //toWrap.addActions(myArray);
            Parcelable n = Parcels.wrap(toWrap);

            //call method from ConnService to send notification to server
            ConnService.sendNotification(this, n);
        }

    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        ConnService.disconnect(getApplicationContext());
    }


    @Override
    public void onNotificationRemoved(StatusBarNotification sbn) {
        Log.i("Msg", "Notification Removed");
    }

    public  boolean checkValidNotification(String packageName, String key){
        for(String str: myList){
            if(str.equals(packageName))
                return true;
        }
        return false;
    }

}
