#include "matrix.h"

int main()
{
    cout << "\t\tMatrix calc" << endl;
    int n;
    while(true)
    {
        cout << "Enter length of matrix's side: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "Error: wrong input of data" << endl;
            system("pause");
        } else
        {
            break;
        }
    }

    char from_file;
    while (true)
    {
        cout << "Would you like to get matrix from file(\"matrix.txt\")(y/n): ";
        cin >> from_file;
        if (from_file == 'y')
        {
            ofstream fout;
            fout.open("matrix.txt");
            cout << "Enter matrix to the file" << endl;
            fout.close();
            system("pause");
            from_file = 1;
            break;
        } else
        if (from_file == 'n')
        {
            from_file = 0;
            break;
        } else
        {
            cout << "Error: wrong input of data" << endl;
        }
    }

    matrix mat = matrix (n, from_file);
    system("cls");
    while (true)
    {
        main_menu();
        unsigned short choise;
        cin >> choise;
        if (choise == 1)
        {
            while (true)
            {
                cout << "Would you like to set second matrix via file(\"matrix2.txt\")(y/n): ";
                cin >> from_file;
                if (from_file == 'y')
                {
                    ofstream fout;
                    fout.open("matrix2.txt");
                    cout << "Enter matrix to the file" << endl;
                    fout.close();
                    system("pause");
                    mat.multiply_matrix(true);
                    break;
                } else
                if (from_file != 'n')
                {
                    cout << "Error: wrong input of data;" << endl;
                    system("pause");
                } else
                {
                    mat.multiply_matrix();
                    break;
                }
            }
        } else
        if (choise == 2)
        {
            while (true)
            {
                cout << "Would you like to set second matrix via file(\"matrix2.txt\")(y/n): ";
                cin >> from_file;
                if (from_file == 'y')
                {
                    ofstream fout;
                    fout.open("matrix2.txt");
                    cout << "Enter matrix to the file" << endl;
                    fout.close();
                    system("pause");
                    mat.add_matrix(true);
                    break;
                } else
                if (from_file != 'n')
                {
                    cout << "Error: wrong input of data;" << endl;
                    system("pause");
                } else
                {
                    mat.add_matrix();
                    break;
                }
            }
        } else
        if (choise == 3)
        {
            while (true)
            {
                cout << "Would you like to print matrix to file(\"matrix.txt\")(y/n): ";
                char in_file;
                cin >> in_file;
                if (in_file == 'y')
                {
                    in_file = 1;
                } else
                if (in_file == 'n')
                {
                    in_file = 0;
                } else
                {
                    cout << "Error wrong input of data;" << endl;
                    system("pause");
                }
                mat.print(in_file);
            }
        }else
        if (choise == 4)
        {
            while (true)
            {
                cout << "Would you like to print length of matrix's side(n) to file(\"N.txt\")(y/n): ";
                char in_file;
                cin >> in_file;
                if (in_file == 'y')
                {
                    in_file = 1;
                } else
                if (in_file == 'n')
                {
                    in_file = 0;
                } else
                {
                    cout << "Error wrong input of data;" << endl;
                    system("pause");
                }
                if (in_file == 1)
                {
                    mat.getN(true);
                    break;
                } else
                {
                    cout << "N = " << mat.getN() << ";" << endl;
                    break;
                }
            }
        } else
        if (choise == 5)
        {
            mat.main_diagonal();
        } else
        if (choise == 6)
        {
            mat.secondary_diagonal();
        } else
        if (choise == 7)
        {
            mat.sort_matrix();
        } else
        if (choise == 8)
        {
            system("cls");
            cout << "Are you sure you want to exit(y/n)? ";
            cin >> choise;
            if (char(choise) == 'y')
            {
                break;
            } else
            if (char(choise) != 'n')
            {
                cout << "Error: wrong input of data" << endl;
                system("cls");
            }
        } else
        {
            cout << "Error: wrong input of data" << endl;
            system("pause");
        }
        system("cls");
    }

    return 0;
}
