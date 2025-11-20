package com.example.a2100998_1017;

import android.annotation.SuppressLint;
import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.graphics.Color;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.PopupMenu;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity {
    View mainView;
    TextView textView;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        mainView =(View)findViewById(R.id.main);
        textView= (TextView) findViewById(R.id.textView);
        Button button = (Button) findViewById(R.id.button);
        Button dateBtn = (Button)findViewById(R.id.button2);
        Button timeBtn = (Button)findViewById(R.id.button4);
        EditText dateText = (EditText)findViewById(R.id.editTextText);
        EditText timeText = (EditText)findViewById(R.id.editTextText2);

        Calendar calendar = Calendar.getInstance();
        int year = calendar.get(Calendar.YEAR);
        int month = calendar.get(Calendar.MONTH);
        int day = calendar.get(Calendar.DAY_OF_MONTH);
        int hour = calendar.get(Calendar.HOUR);
        int minute = calendar.get(Calendar.MINUTE);

        textView.setText("현재 : "+ year + "-"+(month+1)+"-"+day+"-"+hour+":"+minute);

        timeBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TimePickerDialog timePickerDialog = new TimePickerDialog(
                        MainActivity.this, new TimePickerDialog.OnTimeSetListener() {
                    @Override
                    public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
                        timeText.setText("선택한 시간: "+ hourOfDay+" : "+minute);
                    }
                },hour,minute,true);
                timePickerDialog.show();
            }
        });
        dateBtn.setOnClickListener((new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DatePickerDialog datePickerDialog = new DatePickerDialog(MainActivity.this, new DatePickerDialog.OnDateSetListener() {
                    @Override
                    public void onDateSet(DatePicker view, int year, int month, int dayOfMonth) {
                        dateText.setText("선택한 날짜: "+year+"-"+ (month+1) +"-"+dayOfMonth);
                    }
                },year,month,day);
                datePickerDialog.show();
            }
        }));

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                PopupMenu popupMenu = new PopupMenu(MainActivity.this,button);
                popupMenu.getMenuInflater().inflate(R.menu.mymenu,popupMenu.getMenu());
                popupMenu.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {
                    @Override
                    public boolean onMenuItemClick(MenuItem item) {
                       Toast.makeText(getApplicationContext(),"선택한 항목: "+item.getTitle(),Toast.LENGTH_SHORT).show();
                        return true;
                    }
                });

                popupMenu.show();
            }
        });

        registerForContextMenu(textView);
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);
//        MenuInflater menuInflater = getMenuInflater();
//        menuInflater.inflate(R.menu.mymenu, menu);
        menu.setHeaderTitle("컨텍스트 메뉴");
        menu.add(0,1,0,"파랑");
        menu.add(0,2,0,"초록");
        menu.add(0,3,0,"빨강");
    }

    @Override
    public boolean onContextItemSelected(@NonNull MenuItem item) {
        if(item.getItemId() == 1){
            textView.setTextColor(Color.BLUE);
            return true;
        }
        else if(item.getItemId()==2){ // == else if(item.getItemId()==R.id.green)
            textView.setTextColor(Color.GREEN);
            return true;
        }
        else if(item.getItemId()==3){
            textView.setTextColor(Color.RED);
            return true;
        }
        else if(item.getItemId()==R.id.sub1){
            Toast.makeText(getApplicationContext(),"서브메뉴1 선택", Toast.LENGTH_SHORT).show();
            return true;
        }
        return super.onContextItemSelected(item);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.mymenu,menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        if(item.getItemId() == R.id.blue){
            mainView.setBackgroundColor(Color.BLUE);
            return true;
        }
        else if(item.getItemId()==R.id.green){
            mainView.setBackgroundColor(Color.GREEN);
            return true;
        }
        else if(item.getItemId()==R.id.red){
            mainView.setBackgroundColor(Color.RED);
            return true;
        }
        else if(item.getItemId()==R.id.sub1){
            Toast.makeText(getApplicationContext(),"서브메뉴1 선택", Toast.LENGTH_SHORT).show();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}