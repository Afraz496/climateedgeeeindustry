package com.iot.climateedge.myapplication;


import java.util.Vector;

//class to decide statistics for the farmer from the sensor data.


//INPUTS:
// A vector of any type.

//METHODS:

//MIN: Finds the minimum element in a vector.

//MAX: Finds the maximum element in a vector.

//AVG: Finds the average of all the values in the vector.
public class statistics {



    float min(Vector<Object> values){
        float temp;
        temp = (float)values.get(0);

        for(int i = 0;i < values.size();i++){
            if(temp < (float)values.get(i)){
                temp = (float)values.get(i);
            }
        }
        return temp;
    }

    float max(Vector<Object> values){
        float temp;
        temp = (float)values.get(0);

        for(int i = 0;i < values.size();i++){
            if(temp > (float)values.get(i)){
                temp = (float)values.get(i);
            }
        }
        return temp;
    }

    float avg(Vector<Object> values){
        float sum = 0;
        float average;
        for(int i = 0;i < values.size();i++){
            sum = sum + (float)values.get(i);
        }
        average = sum/values.size();
        return average;
    }
}
