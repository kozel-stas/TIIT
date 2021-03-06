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
        if (str1.equals("{}"))
        {
            info=new String[1];
            info[0]="empty";
        }
        else {
            while (i1 != height1 - 1) {
                i2 = Test(i1 + 1, str1);
                shet++;
                i1 = i2;
            }
            i1 = i2 = 0;
            info = new String[shet];
            while (i1 != height1 - 1) {
                i2 = Test(i1 + 1, str1);
                info[Number] = str1.substring(i1 + 1, i2);
                i1 = i2;
                Number++;
            }
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
                    if (CutStr1[i].charAt(0)=='{' && CutStr2[g].charAt(0)=='{')
                    {
                        if (RekSet(CutStr1[i],CutStr2[g])==1)
                            shet++;
                    }
                    else {
                        if (CutStr1[i].charAt(0) == '<' && CutStr2[g].charAt(0) == '<') {
                            if (Korteziki(CutStr1[i],CutStr2[g])==1)
                                shet++;
                        } else
                            shet++;
                    }
            }
            if (shet==Powerstr2)
            {
                    str+=CutStr1[i];
                    str+=',';
            }
        }
        if (str.length()!=0) {
            str = str.substring(0, str.length() - 1);
        }
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
                if (Difference(Score[i],Score[g]).length()!=0)
                Betastr+=',';
                Betastr+=Difference(Score[g],Score[i]);
                if (Difference(Score[g],Score[i]).length()!=0)
                Betastr+=',';
            }
        }
        if (Betastr.length()>1)
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
                if (CutStr1[i].equals(Score[g])==false) {
                    if (CutStr1[i].charAt(0)=='{' && CutStr2[g].charAt(0)=='{')
                    {
                        if (RekSet(CutStr1[i],CutStr2[g])==1)
                            shet++;
                    }
                    else {
                        if (CutStr1[i].charAt(0) == '<' && CutStr2[g].charAt(0) == '<') {
                            if (Korteziki(CutStr1[i], CutStr2[g]) == 1)
                                shet++;
                        } else
                            shet++;
                    }
                }
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
            for (int i=Start;i<Len;i++)
            {
                if (str.charAt(i)==',' || str.charAt(i)=='}' || str.charAt(i)=='>')
                {
                    End=i;
                    break;
                }
            }
        }
        return End;
    }

    public static int Check (String str)
    {
     int Stop=0;
     String[] Checking;
     int len,shet;
     Checking=Cutting(str);
     len=Checking.length;
     for (int i=0;i<len-1;i++) {
         shet = 0;
         for (int j = i + 1; j < len; j++) {
             if (Checking[i].equals(Checking[j]) == false) {
                shet++;
             }
         }
         if (shet!=len-1-i)
             Stop=58;
     }
     return Stop;
    }

    public static int RekSet(String str1,String str2)
    {
        int sh;
        int ans=0;
        int PowStr1,PowStr2;
        String[] a,b;
        a=Cutting(str1);
        PowStr1=a.length;
        b=Cutting(str2);
        PowStr2=b.length;
        for (int i=0;i<PowStr1;i++)
        {
            sh=0;
            for (int g=0;g<PowStr2;g++)
            {
                if (a[i].equals(b[g])==false) {
                    if (a[i].charAt(0) == '{' && b[g].charAt(0) == '{') {
                        if (RekSet(a[i], b[g])==1)
                            sh++;
                    } else {
                        if (a[i].charAt(0) == '<' && b[g].charAt(0) == '<') {
                            if (Korteziki(a[i],b[g])==1)
                                sh++;
                        } else {
                            sh++;
                        }
                    }
                }
            }
            if (sh==PowStr2)
            {
                ans=1;
                break;
            }
        }
        return ans;
    }

    public static int Korteziki (String str1, String str2)
    {
        int ans=0;
        int sh=0;
        String[] a,b;
        a=Cutting(str1);
        b=Cutting(str2);
        for (int i=0;i<2;i++)
        {
            sh=0;
            if (a[i].equals(b[i])==false)
            {
                if (a[i].charAt(0) == '{' && b[i].charAt(0) == '{') {
                        if (RekSet(a[i],b[i])==0)
                            sh++;
                } else {
                    if (a[i].charAt(0) == '<' && b[i].charAt(0) == '<') {
                        if (Korteziki(a[i],b[i])==0)
                            sh++;
                    }
                }
            }
            else
            {
                sh++;
            }
            if (sh==0)
            {
                ans=1;
                break;
            }
        }
        return ans;
    }

}