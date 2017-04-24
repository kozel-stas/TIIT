package com.company;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        boolean Cycle = true;
        int doit,iz;
        String in;
        Scanner What = new Scanner(System.in);
        Scanner St = new Scanner(System.in);
        while (Cycle == true) {
            System.out.println(" 1-Добавить множество\n 2-Выход");
            doit = What.nextInt();
            switch (doit)
            {
                case 1:
                    System.out.println("Введите строку: ");
                    in = St.nextLine();
                    iz=Scores.Check(in);
                    if (iz==0)
                    Scores.AddScore(in);
                    else
                    System.out.println("Введите множество без кратного вхождения элемента");
                    break;
                case 2:
                    Cycle = false;
                    break;
                default:
                    System.out.println("Попробуйте еще раз");
                    break;
            }
        }
        Scores.SimDif();
    }
}
