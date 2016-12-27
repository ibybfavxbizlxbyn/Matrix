#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

void main_menu();

class matrix
{
private:
    unsigned int n;     // quantity of matrix elements
    int* mat;  // matrix


    /*
        File Existence Method
    */
    bool is_file (const string file_name = "matrix.txt") const
    {
        ifstream fin;

        if (file_name == "matrix.txt")
        {
            fin.open("matrix.txt");
        } else
        if (file_name == "matrix2.txt")
        {
            fin.open("matrix2.txt");
        } else
        if (file_name == "matrix_mult.txt")
        {
            fin.open("matrix_mult.txt");
        } else
        if (file_name == "N.txt")
        {
            fin.open("N.txt");
        }

        if (!fin.is_open())
        {
            cout << "Error: No such file(\"" << file_name << "\");" << endl;
            cout << "Would you like to create file \"" << file_name << "\"(y/n): ";
            char answer;
            cin >> answer;
            if (answer == 'y')
            {
                ofstream fout;
                if (file_name == "matrix.txt")
                {
                    fout.open("matrix.txt");
                } else
                if (file_name == "matrix2.txt")
                {
                    fout.open("matrix2.txt");
                } else
                if (file_name == "matrix_mult.txt")
                {
                    fout.open("matrix_mult.txt");
                } else
                if (file_name == "N.txt")
                {
                    fout.open("N.txt");
                }
                cout << "File \"" << file_name << "\" was sucessful created;" << endl;
                fout.close();
            } else
            if (answer != 'n')
            {
                cout << "Error: wrong input of data" << endl;
            }
        } else
        {
            fin.close();
            return true;
        }
        fin.close();
        return false;
    }


    /*
        File Print Method
    */
    void file_print(const string file_name = "matrix.txt", const int mat = 1) const
    {
        ofstream fout;
        if (file_name == "matrix.txt")
        {
            fout.open("matrix.txt");
        } else
        if (file_name == "matrix_mult.txt")
        {
            fout.open("matrix_mult.txt");
        } else
        if (file_name == "matrix_summ.txt")
        {
            fout.open("matrix_summ.txt");
        }

        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                fout << this->mat[this->n*i+j] << " ";
            }
        }
        fout.close();
    }


    /*
        File Read Method
    */
    void file_read (const string file_name = "matrix.txt")
    {
        ifstream fin;
        if (file_name == "matrix.txt")
        {
            fin.open("matrix.txt");
        } else
        if (file_name == "matrix2.txt")
        {
            fin.open("matrix2.txt");
        }

        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                fin >> this->mat[this->n*i+j];
            }
        }
        fin.close();
    }


    /*
        Console Print Method
    */
    void console_print() const
    {
        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                cout << this->mat[this->n*i+j] << " ";
            }
            cout << endl;
        }
    }


    /*
        Console Read Method
    */
    void console_read ()
    {
        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                cin >> this->mat[this->n*i+j];
            }
        }
    }

public:

    /*
        Constructor
    */
    matrix (const int n, const bool from_file = false)
    {
        this->n = n;
        this->mat = new int[this->n*this->n];
        if (from_file == false)
        {
            cout << "Input main matrix:" << endl;
            this->console_read();
        } else
        {
            this->is_file();
            this->file_read();
        }
    }


    /*
        Destructor
    */
    ~matrix ()
    {
        cout << "\t Deleting matrix" << endl;
        this->console_print();

        cout << "Would you like to save matrix to file(\"matrix.txt\")(y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'y')
        {
            this->is_file();
            this->file_print();
        } else
        if (answer != 'n')
        {
            cout << "Error: wrong input of data" << endl;
        }
        delete [] this->mat;
    }


    /*
        Print Method
    */
    void print (const bool in_file = false)
    {
        if (in_file == false)
        {
            cout << "Main matrtix: " << endl;
            this->console_print();
        } else
        {
            this->is_file();
            this->file_print();
            cout << "Matrix was successfully writed to file(\"matrix.txt\");" << endl;
        }
    }


    /*
        Get Methods
    */

    //File: "N.txt"
    int getN (bool in_file = false) const
    {
        if (in_file == true)
        {
            this->is_file("N.txt");
            this->file_print("N.txt");
        } else
        {
            return this->n;
        }
        return 0;
    }

    int* getMatrix () const
    {
        return this->mat;
    }


    /*
        Matrix multiplication Method
    */
    int* multiply_matrix(const bool from_file = false)
    {
        int* mat2 = new int[this->n*this->n];
        if (from_file == false)
        {
            cout << "Enter second matrix: " << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> mat2[this->n*i+j];
                }
            }
        } else
        {
            this->is_file("matrix2.txt");
            this->file_read("matrix2.txt");
        }

        int* mat3 = new int[this->n*this->n];

        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                mat3[this->n*i+j] = 0;
                for (int k = 0; k < this->n; k++)
                {
                    mat3[this->n*i+j] += this->mat[this->n*i+k] * mat2[this->n*k+j];
                }
            }
        }

        cout << "Would you like to save matrix to the file(\"matrix_mult.txt\")(y/n): ";
        char in_file;
        cin >> in_file;
        if (in_file == 'y')
        {
            this->is_file("matrix_mult.txt");
            ofstream fout;
            fout.open("matrix_mult.txt");
            for (int i = 0; i < this->n; i++)
            {
                for (int j = 0; j < this->n; j++)
                {
                    fout << mat3[this->n*i+j] << " ";
                }
                fout << "\r\n";
            }
            fout.close();
            cout << "Multiplication result was successfully writed to file(\"matrix_mult.txt\");" << endl;
        }else
        if (in_file != 'n')
        {
            cout << "Error: wrong input of data;" << endl;
        }

        if (in_file == 'y')
            return NULL;
        cout << "Multiplication result: " << endl;
        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                cout << mat3[this->n*i+j] << " ";
            }
            cout << endl;
        }

        system("pause");
        return mat3;
    }


    /*
        Matrix addind Method
    */
    int* add_matrix (bool from_file = false)
    {
        int* mat2 = new int[this->n*this->n];
        if (from_file == false)
        {
            cout << "Enter second matrix: " << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> mat2[this->n*i+j];
                }
            }
        } else
        {
            this->is_file("matrix2.txt");
            this->file_read("matrix2.txt");
        }

        int* mat3 = new int[this->n*this->n];

        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                mat3[this->n*i+j] = mat[this->n*i+j] + mat2[this->n*i+j];
            }
        }

        cout << "Would you like to save matrix to the file(\"add_mult.txt\")(y/n): ";
        char in_file;
        cin >> in_file;
        if (in_file == 'y')
        {
            this->is_file("add_mult.txt");
            ofstream fout;
            fout.open("add_mult.txt");
            for (int i = 0; i < this->n; i++)
            {
                for (int j = 0; j < this->n; j++)
                {
                    fout << mat3[this->n*i+j] << " ";
                }
                fout << "\r\n";
            }
            fout.close();
            cout << "Mutrix summ was successfully writed to file(\"matrix_mult.txt\");" << endl;
        }else
        if (in_file != 'n')
        {
            cout << "Error: wrong input of data" << endl;
        }

        if (in_file == 'y')
            return NULL;
        cout << "Matrix summ: " << endl;
        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                cout << mat3[this->n*i+j] << " ";
            }
            cout << endl;
        }

        system("pause");
        return mat3;
    }

};

#endif // MATRIX_H_INCLUDED
