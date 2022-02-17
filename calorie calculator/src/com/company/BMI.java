package com.company;

public class BMI {

        public static String BodyMassIndex(double weight, double height){
            String resultBMI = null;
        double bmi = weight/((height/100)*(height/100));
            bmi = Math.floor(bmi*100) /100.0;
            //System.out.println(bmi);
        if(bmi < 16){
            resultBMI = bmi + " = Выраженный дефицит массы тела";
        }else if(bmi > 16 && bmi < 18.5){
            resultBMI = bmi + " = Недостаточная (дефицит) масса тела";
        }else if(bmi >= 18.5 && bmi < 25){
            resultBMI = bmi + " = Здоровый вес (норма)";
        }else if(bmi >= 25 && bmi < 30){
            resultBMI = bmi + " = Избыточная масса тела (предожирение)";
        }else if(bmi >= 30 && bmi < 35){
            resultBMI = bmi + " = Ожирение 1 степени";
        }else if(bmi >= 35 && bmi < 40){
            resultBMI = bmi + " = Ожирение 2 степени";
        }else if(bmi >= 40){
            resultBMI = bmi + " = Ожирение 3 степени";
        }
        return resultBMI;
    }
}
