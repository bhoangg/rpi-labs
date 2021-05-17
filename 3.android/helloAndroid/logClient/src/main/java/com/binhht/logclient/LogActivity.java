package com.binhht.logclient;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;

import com.binhht.logservice.ILogService;

public class LogActivity extends AppCompatActivity {
    private static final String TAG = LogActivity.class.getSimpleName();
    ILogService logService;
    LogActivity.LogConnection conn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_log);

        // Request bind to the service
        conn = new LogActivity.LogConnection();
        Intent intent = new Intent("com.binhht.logservice.ILogService");
        intent.setPackage("com.binhht.logservice");
        bindService(intent, conn, Context.BIND_AUTO_CREATE);
        findViewById(R.id.button2).setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                if (logService != null) {
                    try {
                        logService.log_d("Java", "I'm Java ");
                    } catch (RemoteException e) {
                        Log.e(TAG, "onClick failed", e);
                    }
                }
            }
        });
        findViewById(R.id.button3).setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                if (logService != null) {
                    try {
                        logService.log_d("Native", "I'm Native ");
                    } catch (RemoteException e) {
                        Log.e(TAG, "onClick failed", e);
                    }
                }
            }
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.d(TAG, "onDestroyed");
        unbindService(conn);
        logService = null;
    }

    class LogConnection implements ServiceConnection {
        public void onServiceConnected(ComponentName name, IBinder service) {
            logService = ILogService.Stub.asInterface(service);
            Log.i(TAG, "connected");
        }

        public void onServiceDisconnected(ComponentName name) {
            logService = null;
            Log.i(TAG, "disconnected");
        }
    }
}