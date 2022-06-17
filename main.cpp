
#include <iostream>
using namespace std;

int main()
{
    unsigned short int problema;
    cout << "Introduzca el numero del problema " << endl;
    cin>>problema;

    switch(problema){


//---------------------------------------------------------------------------------------------------------------------------------------

    case(1):{
        char letra;
        int ascii;

        cout<<"introduzca un caracter"<<endl;
        cin>>letra;
        ascii=letra;
        //definimos los limites dentro de los que se encuentran todo el abecedario en el codigo ASCII
        //discriminamos los valores decimales del codigo ASCII para las vocales tanto en minusculas como en mayusculas
        //para poder diferenciar vocales de consonantes dentro del rango del abecedario
        if((ascii>=65 && ascii<=90) || (ascii>=97 && ascii<=122)){
            if (ascii==65 || ascii==97 || ascii==69 || ascii==101 || ascii==73 || ascii==105 || ascii==79 || ascii==111
                    || ascii==85 || ascii==117){
                cout<<letra<<" es una vocal"<<endl;
            }
            else{
                cout<<letra<<" es una consonante"<<endl;
            }

        }

        else{  //si el caracter ingresado no se encuentre entre los valores limitados arriba, quiere decir que no pertenece al abecedario
             cout<<" no es una letra"<<endl;
            }
        break;
    }

//---------------------------------------------------------------------------------------------------------------------------------------

    case(3):{
        int mes, dia;
        cout<<"introduzca el dia"<<endl;
        cin>>dia;
        cout<<"introduzca el numero del mes"<<endl;
        cin>>mes;

        if(mes>=1 && mes<=12){ //todos los meses deben de cumplor ser mayores a 1 y menores a 12

                if(mes==2 && dia==29){  //incluimos la opcion particular en el que se de la combinacion 2/29, caso posible unicamente en año bisiesto
                   cout<<dia<<"/"<<mes<<" valido en bisiesto"<<endl;
                   break;
                }

                if(dia>=1 && dia<=31){ //los dias deben de estar limitados desde 1 hasta 31
                    cout<<dia<<"/"<<mes<<" es una fecha valida"<<endl;
                }

                else{
                     cout<<dia<<"/"<<mes<<" no es una fecha valida"<<endl; //si no se cumple con el limite de los dias, la fecha ingresada no es valida
                }
        }


        else{
             cout<<dia<<"/"<<mes<<" no es una fecha valida"<<endl;  //si no se cumple con los limites de los meses, la fecha ingresada no es valida
        }
        break;
    }

//---------------------------------------------------------------------------------------------------------------------------------------



    case(5):{
        int n=1,N;
        cout<<"introduzca un numero impar"<<endl;
        cin>>N;
        for (int i=0;i<=N; i++){

            if(i<=N/2){ //dividimos el rombo en dos, un triangulo superior y un triangulo inferior

                for(int j=1;j<=(N-(2*i+1))/2;j++){ //generamos los espacios adicionales a la izquierda de mayor a menor cantidad: ...3,2,1
                    cout<<" ";
                }

                for (int j=1; j<=(2*i+1) ;j++){ //creamos los asteriscos del triangulo, por grupos impares: 1,3,5....hasta llegar a N asteriscos

                    if(2*i+1>N){ //cuando hemos creado una linea de N asteriscos, rompemos el ciclo para evitar lineas extras.
                        break;
                    }
                    cout<<"*";
                }
                cout<<endl;
            }

            else{ //creamos la parte inferior del rombo

                for(int j=1;j<=i-(N/2);j++){ //nuevamente, creamos primero los espacios a la izquierda, esta vez de menor a mayor:1,2,3...
                    cout<<" ";

                }

                for (int j=1; j<=N-(2*n);j++){ //creamos las filas de rombos necesarias hasta llegar a un unico asterisco

                     cout<<"*";
                }
                n+=1;
                cout<<endl;
            }
        }
        break;
    }




//---------------------------------------------------------------------------------------------------------------------------------------


    case(7):{
        int n,A=0,fib=1,actual=1,suma=0;
        cout<<"ingrese un numero n";
        cin>>n;

        cout<<"1"<<endl;

        for(int i=1;fib<=n;i++){ //creamos la sucesion de fibonacci
            fib=A+actual;
            A=actual;
            actual=fib;
            if(fib>n){ //si el valor de la sucesion supera el valor ingresado, se rompe el ciclo
                break;
            }
            else if(fib%2==0){ // verificamos si el valor de la sucesion es par, de ser asi, lo agregamos a la suma
                suma=suma+fib;
            }
        }
        cout<<"el resultado de la suma es "<<suma<<endl;
        break;

    }


//---------------------------------------------------------------------------------------------------------------------------------------



    case(9):{
            int N,red,total,suma = 0;
            float n,reduccion;

            cout<<"ingrese un numero N"<<endl; //tomemos el ejemplo con 125;
            cin>>N;
            n=N+0.01;  //ajustamos el valor ingresado para que al hacer la separacion del numero ingresado aproxime hacia arriba; ejem=125.01
                       //la idea es seccionar el valor N en unidades, decenas, centenas, etc
            while(n>1){
            int potencia=1;
            reduccion=n/10;  //dividimos el valor float sobre 10; ejm 12.501
            n=reduccion;     //actualizamos el valor de n
            red=reduccion;   //eliminamos la parte decimal del float convirtiendolo en un int; ejem 12
            total=10*(reduccion-red); //  10*(12.501-12)= 10*(0.501)= 5.01 --> al convertirlo al int nos quedamos solo con 5, es decir la unidad
                                      //repetimos para las centenas, las decenas, um,dm...
            for(int i=1;i<=total;i++){  //realizamos la potenciacion
                potencia=potencia*total;
            }
            suma=suma+potencia; //sumamos las potencias
            }
            cout<<"el resultado de la suma es: "<<suma<<endl;
            break;
    }


//---------------------------------------------------------------------------------------------------------------------------------------

    case(11):{
        int N,a,d=0,t=0,c=0,dt=0,tt=0,ct=0,s=0,st=0,potencias_dos=1, potencias_tres=1, potencias_cinco=1, potencias_siete=1;
        cout<<"Ingrese un valor N ";
        cin>>N;
        for(int i=2;i<=N;i++){
            a=i;
            d=0;
            t=0;
            c=0;
            s=0;
            for (int j=2; a!=1; j++){
               if (a%j==0){

                   while(a%j==0 || a!=1){
                   a=a/j;                     //realizamos la descomposicion del numero en los cuatro primeros numeros primos
                   if(j==2){                  //tomamos medida del grado de la potencia de cada numero;
                       d=d+1;
                   }
                   if(j==3){
                       t=t+1;
                   }
                   if(j==5){
                       c=c+1;
                   }
                   if(j==7){
                       s=s+1;
                   }
                   }
               }

               if(d>dt){                    //almacenamos el mayor grado al que estan elevados los numeros primos
                   dt=d;
               }
               if(t>tt){
                   tt=t;
               }

               if(c>ct){
                   ct=c;
               }
               if(s>st){
                   st=s;
               }
            }

        }
        for(int i=1;i<=dt;i++){
            potencias_dos=potencias_dos*2;      //realizamos las potencias de los numeros primos elevados a sus respectivos grados
        }

        for(int i=1;i<=tt;i++){
            potencias_tres=potencias_tres*3;
        }

        for(int i=1;i<=ct;i++){
            potencias_cinco=potencias_cinco*5;
        }
        for(int i=1;i<=st;i++){
            potencias_siete=potencias_siete*7;
        }
        cout<<"el minimo comun multiplo es: "<<potencias_dos*potencias_tres*potencias_cinco*potencias_siete<<endl; //sumamos las potencias
        break;
    }

//---------------------------------------------------------------------------------------------------------------------------------------






    case(13):{
        int N, sumatoria=0;
        bool b = false;
        cout<<"Ingrese un numero N"<<endl;
        cin>>N;
        for(int i=2;i<N;i++){       //comenzamos desde el primer numero primo=2 y recorremos hasta N.
            b=false;
            for(int j=2; j<=i-1;j++){       //corroboramos que cada numero es primo, si encontramos un valor diferente a 1 y al mismo
                if(i%j==0){                 // numero para el cual su modulo sea igual a cero, podemos descartarlo como primo
                  b=true;
                  break;
                }
            }
            if(b==false){                   //de lo contrario este numero es primo y podemos añadirlo a la sumatoria
                sumatoria=sumatoria+i;
            }
         }
            cout<<"el resultado de la suma es: "<< sumatoria;
          break;

    }


//---------------------------------------------------------------------------------------------------------------------------------------

    case(15):{

        int N,cuadrado;
        cout<<"Ingrese un numero N"<<endl;
        cin>>N;
        cuadrado=N*N;                   //hallamos el valor maximo de la espiral que sera NxN
        int sumaExt=cuadrado;
        for(int i=0;i<=(N-(2*i+1));i++){   //generamos la distancia que hay entre cada esquina de la espiral, por ejemplo,
                                           // entre 25,21,17,13 hay una distancia de 4, entre , 9,7,5,3 hay una distancia de 2;


            for(int j=1;j<=4;j++){                      //la espiral tiene cuatro lados, realizamos la operacion para cada lado
                sumaExt=sumaExt+(cuadrado-(N-(2*i+1))); //al numero actual de la espiral le sumamos el numero actual de la espiral menos la distancia
                                                        //entre las esquinas, por ejemplo 25+(25-4)=25+21

                cuadrado=cuadrado-(N-(2*i+1));          //nos posicionamos en el siguiente valor de la espiral, siempre de mayor a menor, si estabamos en 25
                                                        //ahora nos ubicaremos en el 21, del 21 al 17 y asi sucesivamente hasta llegar al 1.

                }


        }
        cout<<"en una espiral de "<<N<<"*"<<N<<", la suma es: "<< sumaExt<<endl;
        break;
    }
//---------------------------------------------------------------------------------------------------------------------------------------

    case(17):{
        int k,trian,div=0;
        bool b = false;
        cout<<"ingrese un numero K "<<endl;
        cin>>k;
        while(div!=k){                      //entraremos al ciclo hasta que obtengamos un numero de divisiores igual a la entrada k
            for(int n=1;b==false;n++){
                div=0;
                trian=n*(n+1)/2;            //generamos la serie triangular

                    for(int j=1;j<=trian;j++){
                        if(trian%j==0){     //hallamos todos los divisiores de cada valor de la serie
                            div=div+1;      //acumulamos la cantidad de divisores de cada numero de la serie
                            if(div==k){     //cuando la cantidad de divisores sea igual al valor ingresado, imprimimos el resultado y
                                b=true;     //rompemos el ciclo.
                                cout<<"el numero es "<<trian<<" que tiene "<<div<<" divisores"<<endl;
                                break;
                            }
                        }
                    }
            }
        }
        break;
    }


}
    return 0;
}
