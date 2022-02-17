package com.company;

public class Calorie_calc {
    public static double calculateCalorie(boolean male, int weight, int height, int age, double multiplier){
        double result;
        if(male) {
            result = (10 * weight + 6.25 * height - 5 * age + 5) * multiplier;
        }
        else {
            result = (10 * weight + 6.25 * height - 5 * age - 161) * multiplier;
        }
        return result;
    }
}
