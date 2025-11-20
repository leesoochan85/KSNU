package com.example.b2201024_0930;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.Toast;

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

        CheckBox checkBox = (CheckBox) findViewById(R.id.checkBox);
        CheckBox checkBox2 = (CheckBox) findViewById(R.id.checkBox2);
        ImageView imageView = (ImageView) findViewById(R.id.imageView);
        ImageView imageView2 = (ImageView) findViewById(R.id.imageView2);
        RadioButton redBtn = (RadioButton) findViewById(R.id.radioButton);
        RadioButton greenBtn = (RadioButton) findViewById(R.id.radioButton2);
        RadioButton blueBtn = (RadioButton) findViewById(R.id.radioButton3);
        LinearLayout layout = (LinearLayout) findViewById(R.id.main);
        Button button = (Button) findViewById(R.id.button3);

        imageView.setImageResource(0);
        imageView2.setImageResource(0);

        checkBox.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(@NonNull CompoundButton buttonView, boolean isChecked) {
                if (isChecked) imageView.setImageResource(R.drawable.sand1);
                else imageView.setImageResource(0);
            }
        });

        checkBox2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(@NonNull CompoundButton buttonView, boolean isChecked) {
                if (isChecked) imageView2.setImageResource(R.drawable.sand2);
                else imageView2.setImageResource(0);
            }
        });

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(redBtn.isChecked()) layout.setBackgroundColor(Color.RED);
                else if(greenBtn.isChecked()) layout.setBackgroundColor(Color.GREEN);
                else if(blueBtn.isChecked()) layout.setBackgroundColor(Color.BLUE);
                else {
                    Toast.makeText(getApplicationContext(),
                            "색상을 선택해 주세요.", Toast.LENGTH_SHORT).show();
                }
            }
        });

    }
}