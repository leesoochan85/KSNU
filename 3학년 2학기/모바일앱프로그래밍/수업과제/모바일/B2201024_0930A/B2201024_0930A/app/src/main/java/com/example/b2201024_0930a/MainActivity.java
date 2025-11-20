package com.example.b2201024_0930a;

import static android.view.View.INVISIBLE;
import static android.view.View.VISIBLE;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.Switch;
import android.widget.Toast;
import android.widget.ToggleButton;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

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

        EditText editText = (EditText) findViewById(R.id.editTextText);
        RadioButton radioButton = (RadioButton) findViewById(R.id.radioButton);
        RadioButton radioButton2 = (RadioButton) findViewById(R.id.radioButton2);
        Button button = (Button) findViewById(R.id.button);
        ImageView imageView = (ImageView) findViewById(R.id.imageView);
        Switch sw = (Switch) findViewById(R.id.switch1);
        ToggleButton toggleButton = (ToggleButton) findViewById(R.id.toggleButton);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (radioButton.isChecked()) {
                    try {
                        Double ct = Double.valueOf(editText.getText().toString());
                        Double ft = ((ct * 9) / 5 ) + 32;
                        editText.setText(""+ ft);
                    } catch (Exception e){
                        Toast.makeText(getApplicationContext(),
                                "온도를 숫자로 입력하세요.", Toast.LENGTH_SHORT).show();
                    }
                } else if (radioButton2.isChecked()){
                    try {
                        Double ft = Double.valueOf(editText.getText().toString());
                        Double ct = ((ft - 32) * 5 / 9);
                        editText.setText(""+ ct);
                    } catch (Exception e) {
                        Toast.makeText(getApplicationContext(),
                                "온도를 숫자로 입력하세요.", Toast.LENGTH_SHORT).show();
                    }
                } else {
                    Toast.makeText(getApplicationContext(),
                            "화씨 또는 섭씨를 선택해주세요.", Toast.LENGTH_SHORT).show();
                }
            }
        });

        sw.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(@NonNull CompoundButton buttonView, boolean isChecked) {
                if(isChecked) imageView.setImageResource(R.drawable.on);
                else imageView.setImageResource(R.drawable.off);
            }
        });

        toggleButton.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(@NonNull CompoundButton buttonView, boolean isChecked) {
                if(isChecked) imageView.setVisibility(VISIBLE);
                else imageView.setVisibility(INVISIBLE);
            }
        });
    }
}