package com.company;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;

import java.net.URL;
import java.util.ResourceBundle;

public class ControllerForResult implements Initializable {


    @FXML
    private Label mainResult;
    @FXML
    private Label resultBMI;
    @FXML
    private Label mainResultMinusTwentyProcent;
    @FXML
    private Label mainResultMinusFourtyProcent;


    public static String BMI;
    public static double result;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        mainResultMinusTwentyProcent.setText((int) (result * 0.8) + " ккал");
        mainResultMinusFourtyProcent.setText((int) (result * 0.6) + " ккал");
        resultBMI.setText(BMI);
        mainResult.setText((int) result + " ккал");

    }
}
