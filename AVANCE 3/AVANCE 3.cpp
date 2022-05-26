#include <iostream>
#include <string.h> //para el tamaño
#include <fstream>

using namespace std;

int main()
{
    string nombre[3], tratamiento[3], d[3], h[3];

    struct producto
    {
        float precio;
        float subtotal;
        int cantidad;
        float IVA;
        float total;
        int Lista = 0;
        char nombre[10];
        int d;
        int h;
        char descripcion[30];
    };

    producto orden[3];
    int buscar;
    int letras = 0;
    fstream escritorLector;
    int a, contador = 0;
    int incrementar = 0;

    cout << endl << endl;
    cout << endl << endl;



    a = 0;
    while (a != 5)
    {
        //Presionar f5 para compilar

        system("cls");
        cout << "D E N T I S T A" << endl;
        cout << endl << endl;

        cout << "> M E N U <" << endl;
        cout << endl << endl;

        cout << "Eliga la opci\242n que desea" << endl;
        cout << endl << endl;
        cout << "1. Agendar cita " << endl;
        cout << "2. Imprimir receta " << endl;
        cout << "3. Borrador " << endl;
        cout << "4. Ver agenda" << endl;
        cout << "5. Salir " << endl;
        cin >> a;

        cout << endl << endl;


        switch (a)
        {
        case 1:
            system("cls"); //limpiar pantalla

            cout << "Por favor ingrese los siguientes datos " << endl;

            cout << endl;

            cout << "Nombre del paciente: ";
            cin.ignore();
            cin.getline(orden[contador].nombre, 10);  //getline, para poner espacios

            cout << endl;

            cout << "Dia asignado: ";
            cin >> orden[contador].d;

            cout << endl;

            cout << "Hora asignada: ";
            cin >> orden[contador].h;

            cout << endl;

            cout << "Ingresar descripci\242n: ";
            cin.ignore();
            cin.getline(orden[contador].descripcion, 30);   //getline, para poner espacios

            cout << endl;

            cout << "Cantidad: ";
            cin >> orden[contador].cantidad;

            cout << endl;

            cout << "Precio: ";
            cin >> orden[contador].precio;

            cout << endl;

            orden[contador].subtotal = orden[contador].cantidad * orden[contador].precio;

            cout << "Subtotal: " << orden[contador].subtotal << endl;

            orden[contador].IVA = orden[contador].subtotal * .16;

            cout << "IVA: " << orden[contador].IVA << endl;

            orden[contador].total = orden[contador].subtotal + orden[contador].IVA;

            cout << "Total: " << orden[contador].total << endl;

            contador++;
            orden[contador].Lista++;

            break;
        case 2:
            system("cls");

            if (contador == 0)
            {
                cout << "No hay registro de pacientes";
            }
            else
            {
                for (int i = 0; i < contador; i++)
                {
                    cout << "*****************************" << endl;
                    cout << "Lista: " << orden[i].Lista << endl;
                    cout << "Nombre: " << orden[i].nombre << endl;
                    cout << "Fecha: " << orden[i].d << endl;
                    cout << "Hora: " << orden[i].h << endl;
                    cout << "Descripci\242n: " << orden[i].descripcion << endl;
                    cout << "Cantidad: " << orden[i].cantidad << endl;
                    cout << "Precio: " << orden[i].precio << endl;
                    cout << "Subtotal: " << orden[i].subtotal << endl;
                    cout << "IVA: " << orden[i].IVA << endl;
                    cout << "Total: " << orden[i].total << endl;
                    cout << "*****************************" << endl;
                }
            }
            break;
        case 3:
            system("cls");
            {
                cout << "N\242mero del paciente que desea buscar" << endl;
                cin >> buscar;

                if (contador == 0)
                {
                    cout << "Ya no hay registro de la cita";
                }
                else
                    for (int i = 0; i < contador; i++)
                    {
                        if (buscar == orden[i].Lista)
                        {
                            cout << "*****************************" << endl;
                            cout << "Lista: " << orden[i].Lista << endl;
                            cout << "Nombre: " << orden[i].nombre << endl;
                            cout << "Fecha: " << orden[i].d << endl;
                            cout << "Hora: " << orden[i].h << endl;
                            cout << "Descripci\242n: " << orden[i].descripcion << endl;
                            cout << "Cantidad: " << orden[i].cantidad << endl;
                            cout << "Precio: " << orden[i].precio << endl;
                            cout << "Subtotal: " << orden[i].subtotal << endl;
                            cout << "IVA: " << orden[i].IVA << endl;
                            cout << "Total: " << orden[i].total << endl;
                            cout << "*****************************" << endl;

                            orden[i] = orden[i + 1]; //como para reemplazar
                            contador--;
                        }
                    }
                
            }

            break;
        case 4:
            system("cls");
            if (contador == 0)
            {
                cout << "No hay registro de pacientes";
            }
            else
            {
                cout << "A G E N D A" << endl;
                cout << endl;

                for (int i = 0; i < contador; i++)
                {
                    cout << "*****************************" << endl;
                    cout << "Lista: " << orden[i].Lista << endl;
                    cout << "Nombre: " << orden[i].nombre << endl;
                    cout << "Fecha: " << orden[i].d << endl;
                    cout << "Hora: " << orden[i].h << endl;
                    cout << "Descripci\242n: " << orden[i].descripcion << endl;
                    cout << "Cantidad: " << orden[i].cantidad << endl;
                    cout << "Precio: " << orden[i].precio << endl;
                    cout << "Subtotal: " << orden[i].subtotal << endl;
                    cout << "IVA: " << orden[i].IVA << endl;
                    cout << "Total: " << orden[i].total << endl;
                    cout << "*****************************" << endl;
                }
            }

            break;
        case 5:
        {

            cout << "Saliendo del programa..." << endl;
            cout << endl << endl;
        }

        {
            escritorLector.open("DENTISTA.txt", ios::out);

            for (int i = 0; i < contador; i++)
            {
                escritorLector << "\nLista: " << orden[i].Lista;
                escritorLector << "\nNombre" << orden[i].nombre;
                escritorLector << "\nFecha: " << orden[i].d;
                escritorLector << "\nHora: " << orden[i].h;
                escritorLector << "\nDescripci\242n: " << orden[i].descripcion;
                escritorLector << "\nCantidad: " << orden[i].cantidad;
                escritorLector << "\nPrecio: " << orden[i].precio;
                escritorLector << "\nSubtotal: " << orden[i].subtotal;
                escritorLector << "\nIVA: " << orden[i].IVA;
                escritorLector << "\nTotal: " << orden[i].total;
            }

            escritorLector.close();
        }
        break;
        default:
            cout << "Por favor, ingrese otra opci\242n";
            cout << endl << endl;
            break;
        }

        system("pause>NULL");
    }



    system("pause>NULL");




    return 0;
}