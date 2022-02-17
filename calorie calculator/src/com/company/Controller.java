package com.company;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.stage.Stage;


import java.net.URL;
import java.util.Objects;
import java.util.ResourceBundle;

public class Controller implements Initializable {

    @FXML
    private Button man;
    @FXML
    private Button woman;


    @FXML
    private RadioButton minimal;
    @FXML
    private RadioButton low;
    @FXML
    private RadioButton medium;
    @FXML
    private RadioButton high;
    @FXML
    private RadioButton veryHigh;

    @FXML
    private TextField age;
    @FXML
    private TextField height;
    @FXML
    private TextField weight;

    @FXML
    private Label alert;
    @FXML
    private Label alertNext;

    boolean sex;


    //Выбранный пол мужчина
    @FXML
    public void clickButtonMan(){
        sex = true;
        man.setStyle("-fx-background-color: #ffa01b");
        woman.setStyle("");

    }
    //Выбранный пол женщина
    @FXML
    public void clickButtonWoman(){
        sex = false;
        woman.setStyle("-fx-background-color: #ffa01b");
        man.setStyle("");
    }


    int ageReads = 0;
    int heightReads = 0;
    int weightReads = 0;


    //получение данных введенных в поля
    public void getTextFields() {
        try {
            ageReads = Integer.parseInt(age.getText());
            heightReads = Integer.parseInt(height.getText());
            weightReads = Integer.parseInt(weight.getText());
            //System.out.println(ageReads + " " + heightReads + " " + weightReads);
        }catch (Exception e) {
            alert.setText("*необходимо заполнить поля");
        }
    }

    //получение значения считанного с радиокнопки
    RadioButton selectRadioButton = null;
    @FXML
    public void minimalButton(){
        selectRadioButton = minimal;
    }
    @FXML
    public void lowButton(){
        selectRadioButton = low;
    }
    @FXML
    public void mediumButton(){
        selectRadioButton = medium;
    }
    @FXML
    public void highButton(){
        selectRadioButton = high;
    }
    @FXML
    public void veryHighButton(){
        selectRadioButton = veryHigh;
    }

    //получение значения коэффициента считанного с радиокнопки
    public double getMultiplier(RadioButton button){
        double result = 0;
        if (minimal.equals(button)) {
            result = 1.2;
        } else if (low.equals(button)) {
            result = 1.375;
        }else if (medium.equals(button)) {
            result = 1.55;
        }else if (high.equals(button)) {
            result = 1.725;
        }else if (veryHigh.equals(button)) {
            result = 1.9;
        }
        return result;
    }

    //установка параметров по умолчанию
    public void setDefault(){
        alert.setText("");
        alertNext.setText("");
        clickButtonMan();
        age.setText("0");
        height.setText("0");
        weight.setText("0");
        minimal.fire();
        minimalButton();
    }

    //Создание объекта группа, для объединения радиокнопок
    //чтобы избежать одновременного выбора двух и более кнопок
    ToggleGroup group = new ToggleGroup();
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

        setDefault(); //вызов дефолтных настроек
        // установка группы
        minimal.setToggleGroup(group);
        low.setToggleGroup(group);
        medium.setToggleGroup(group);
        high.setToggleGroup(group);
        veryHigh.setToggleGroup(group);
    }

    //Расчет калорий и получение результата
    public double getCalculateResult(){

        double resultMultiplier = getMultiplier(selectRadioButton); //Полученный коэффициент в зависимости от кнопки
        //System.out.println(resultMultiplier); //проверка результата

        return Calorie_calc.calculateCalorie(sex,weightReads,heightReads,ageReads,resultMultiplier);
    }

    //Расчет ИМТ и получение результата
    public String getBMI() {
        getTextFields();
        return BMI.BodyMassIndex(weightReads,heightReads);
    }

    //Вывод окна с результатом
    @FXML
    public void getResultWindow() throws Exception {
        getTextFields();
        if(ageReads == 0 || heightReads == 0 || weightReads == 0 ){
            alert.setText("*необходимо заполнить поля");
        }else
        if(ageReads >= 13 && ageReads <= 80){
            alert.setText("");
            alertNext.setText("");
            ControllerForResult.result = getCalculateResult(); // Запись в поле Label рассчитанного значения
            ControllerForResult.BMI = getBMI();// Запись в поле Label рассчитанного значения


            Stage window = new Stage();
            Parent root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("resultScene.fxml")));
            window.setScene(new Scene(root));
            window.setTitle("Результат");
            Image icon = new Image(Objects.requireNonNull(getClass().getResourceAsStream("icon.png")));
            window.getIcons().add(icon);
            window.setResizable(false);
            window.show();
        }else {
            alert.setText("*формула активна только для лиц ");
            alertNext.setText("в возрасте от 13 до 80 лет");
        }

    }
}
