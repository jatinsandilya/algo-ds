package com.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * Problem : https://codeforces.com/contest/4/problem/B
 */
public class BeforeExam {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int d = Integer.parseInt(st.nextToken());

        int sumTime = Integer.parseInt(st.nextToken());

        int[] minTimes = new int[d];
        int[] maxTimes = new int[d];
        int[] actualOrder = new int[d];

        for(int i = 0; i < d ; i ++){

            StringTokenizer s = new StringTokenizer(br.readLine());
            int minTime = Integer.parseInt(s.nextToken());
            int maxTime = Integer.parseInt(s.nextToken());

            minTimes[i] = minTime;
            maxTimes[i] = maxTime;
        }


        boolean possible = checkPossibility(sumTime,d,1,minTimes,maxTimes,actualOrder);
        System.out.println( possible? "YES" : "NO");

        if(possible){
            for(int i=0;i<d;i++){
                System.out.print(actualOrder[i]);
                System.out.print(" ");
            }
        }

    }

    private static boolean checkPossibility(int sumTime, int totalDays, int day, int[] minTimes, int[] maxTimes, int[] actualOrder){

        if ( day > totalDays || sumTime < 0 )
            return false;


        for(int time = minTimes[day-1];time <= maxTimes[day-1];time++ ){
            actualOrder[day-1] = time;
            if( time == sumTime|| checkPossibility(sumTime - time,totalDays,day+1,minTimes,maxTimes, actualOrder)) {
                return true;
            }
        }

        return false;
    }
}
