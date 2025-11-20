package com.example.b2201024_0930b;

import android.os.Bundle;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.Toast;
import android.widget.ToggleButton;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    ToggleButton tg, tg2;
    ImageView imageView;
    RatingBar ratingBar;

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

        tg = (ToggleButton) findViewById(R.id.toggleButton);
        tg2 = (ToggleButton) findViewById(R.id.toggleButton2);
        imageView = (ImageView) findViewById(R.id.imageView2);
        ratingBar = (RatingBar) findViewById(R.id.ratingBar);

        tg.setOnCheckedChangeListener(toggleListener);
        tg2.setOnCheckedChangeListener(toggleListener);

        ratingBar.setOnRatingBarChangeListener(new RatingBar.OnRatingBarChangeListener() {
            @Override
            public void onRatingChanged(RatingBar ratingBar, float rating, boolean fromUser) {
                Toast.makeText(getApplicationContext(),
                        "Rating : " + rating, Toast.LENGTH_SHORT).show();
            }
        });
    }

    private CompoundButton.OnCheckedChangeListener toggleListener = new CompoundButton.OnCheckedChangeListener() {
        @Override
        public void onCheckedChanged(@NonNull CompoundButton buttonView, boolean isChecked) {
            if (tg.isChecked() && tg2.isChecked())
                imageView.setImageResource(R.drawable.on1);
            else imageView.setImageResource(R.drawable.off1);

            Toast.makeText(getApplicationContext(),
                    "Rating : " + ratingBar.getRating()
                    , Toast.LENGTH_SHORT).show();
        }
    };
}