package com.example.b2201024_0916a;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    EditText editText, editText2, editText3;

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

        editText = (EditText) findViewById(R.id.editText);
        editText2 = (EditText) findViewById(R.id.editText2);
        editText3 = (EditText) findViewById(R.id.editText3);
    }

    public void addClick(View v) {
        editText3.setText(""); // 시작할때 result값을 없앰

        String str1 = editText.getText().toString();
        String str2 = editText2.getText().toString();

        try{
            double result = Double.parseDouble(str1) + Double.parseDouble(str2);
            // 문자를 실수로 바꿔서 연산

            Log.v("MY_TAG", Double.toString(result));
            editText3.setText(Double.toString(result)); // 실수를 문자열로 바꿔서 출력
        } catch (Exception e){
            Toast.makeText(getApplicationContext(),
                    "입력에 오류가 있습니다.", Toast.LENGTH_LONG).show();
        }

    }
}