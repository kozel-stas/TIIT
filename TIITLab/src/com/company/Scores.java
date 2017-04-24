package com.company;

/**
 * Created by a4tec on 23.04.2017.
 */
public class Scores {
    public static String[] Score,dopScore,CutStr1,CutStr2;
    public static String Outstr,Betastr;
    public static int NumberofScores=0,Powerstr1,Powerstr2;
    public static void AddScore (String str)
    {
        dopScore=new String[NumberofScores];
        for (int i=0;i<NumberofScores;i++)
        {
           dopScore[i]=Score[i];
        }
        Score=new String[NumberofScores+1];
        for (int i=0;i<NumberofScores;i++)
        {
            Score[i]=dopScore[i];
        }
        dopScore=new String[0];
        Score[NumberofScores]=str;
        NumberofScores++;
    }

    public static String[] Cutting (String str1)
    {
        int height1,shet=0;
        int i1=0,i2=0,Number=0;
        height1=str1.length();
        String[] info;
        while (i1!=height1-1)
        {
           i2=Test(i1+1,str1);
           shet++;
           i1=i2;
        }
        i1=i2=0;
        info=new String[shet];
        while (i1!=height1-1)
        {
            i2=Test(i1+1, str1);
            info[Number]=str1.substring(i1+1,i2);
            i1=i2;
            Number++;
        }
        return info;
    }

    public static void Cut(String str1,String str2)
    {
        CutStr1=Cutting(str1);
        Powerstr1=CutStr1.length;
        CutStr2=Cutting(str2);
        Powerstr2=CutStr2.length;
    }

    public static String Difference (String str1,String str2)
    {
        Cut(str1,str2);
        String str="";
        int shet=0;
        for (int i=0;i<Powerstr1;i++)
        {
            shet=0;
            for (int g=0;g<Powerstr2;g++)
            {
                if (CutStr1[i].equals(CutStr2[g])==false)
                    shet++;
            }
            if (shet==Powerstr2)
            {
                    str+=CutStr1[i];
                    str+=',';
            }
        }
        str=str.substring(0,str.length()-1);
        return str;
    }

    public static void SimDif()
    {
        int shet=0;
        Betastr="";
        Betastr+='{';
        for (int i=0;i<NumberofScores-1;i++)
        {
            for (int g=i+1;g<NumberofScores;g++)
            {
                Betastr+=Difference(Score[i],Score[g]);
                Betastr+=',';
                Betastr+=Difference(Score[g],Score[i]);
                Betastr+=',';
            }
        }
        Betastr=Betastr.substring(0,Betastr.length()-1);
        Betastr+='}';
        CutStr1=Cutting(Betastr);
        Powerstr1=CutStr1.length;
        NumberofScores=0;
        Outstr="";
        Outstr+='{';
        for (int i=0;i<Powerstr1;i++)
        {
            shet=0;
            for (int g=0;g<NumberofScores;g++)
            {
                if (CutStr1[i].equals(Score[g])==false)
                    shet++;
            }
            if (shet==NumberofScores)
            {
                AddScore(CutStr1[i]);
                Outstr+=CutStr1[i];
                Outstr+=',';
            }
        }
        Outstr=Outstr.substring(0,Outstr.length()-1);
        Outstr+='}';
        System.out.println(Outstr);
    }

    public static int Test (int Start,String str)
    {
        int Len=str.length();
        int End=0,num=0,j;
        if (str.charAt(Start)=='<' || str.charAt(Start)=='{')
        {
            num++;
            j=Start+1;
            while (num!=0)
            {
                if (str.charAt(j)=='<' || str.charAt(j)=='{')
                    num++;
                if (str.charAt(j)=='>' || str.charAt(j)=='}')
                    num--;
                j++;
            }
            End=j;
        }
        else
        {
            for (int i=Start+1;i<Len;i++)
            {
                if (str.charAt(i)==',' || str.charAt(i)=='}')
                {
                    End=i;
                    break;
                }
            }
        }
        return End;
    }
}
