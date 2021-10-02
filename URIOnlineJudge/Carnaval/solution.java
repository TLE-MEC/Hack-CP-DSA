/**********************************************************************
 * Ejercicio: Carnaval                                                *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/2418 *
 * Lenguaje: Java                                                     *
 * Autor: Jhoser Pacheco                                              *
 *********************************************************************/

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */

//output exercice

public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
	Scanner sc = new Scanner (System.in);
	float vec[] = new float[5];
	int n = 5;
	  for (int j = 0; j < n; j++) {
                vec[j] = sc.nextFloat();
            }
            Arrays.sort(vec);
            
            float xd = vec[1]+vec[2]+vec[3];
            System.out.println(String.format("%.1f",xd));

	}
}