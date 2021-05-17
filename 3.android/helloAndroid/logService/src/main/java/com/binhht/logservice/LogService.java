package com.binhht.logservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

public class LogService extends Service {
//    private static final String TAG = LogService.class.getSimpleName();
    private static final String TAG = "LogService-Java";
    static {
        System.loadLibrary("native");
    }
    @Override
    public void onCreate() {
        super.onCreate();
    }

    @Override
    public IBinder onBind(Intent intent) {
        // Return the interface
        return binder;
    }

    private final ILogService.Stub binder = new ILogService.Stub() {
        public void log_d(String tag, String message) throws RemoteException {
//            Log.d(TAG, "binhht: " + tag + " " + message);
            if (tag.equals("Java"))
                Log.d(TAG, message);
            else
                stringFromJNI(message);
        }
    };

    public native void stringFromJNI(String msg);
}
