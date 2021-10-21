#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

#include <cmath>
#include <algorithm>
#include <new>
#include <vector>

using namespace std;

// alias run='clear && g++ main.cpp -o main.exe; ./main.exe'

int main()
{
    

    return 0;
}

// Ch-13

int ekub(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return ekub(b, a % b);     
}

int main13_1()
{
    int a,b;
    cin >> a >> b;

    cout << ekub(a,b);

  return 0;
}


// Recursion

void printNumRecursion(int a)
{
    if(a <= 100)
    {
        printNumRecursion(a + 1);
        cout << a << " ";
    }
}

int printSumRecursion(int x)
{
    if(x < 1)
    {
        return 1;
    }
    cout << x << " ";
    return printSumRecursion(x - 1) + x;
}

int main_1Recursion()
{
    // printNumRecursion(1);

    cout << printSumRecursion(3) << endl;
    cout << endl;

    return 0;
}

// Ch-12

int main12_13()
{
    int n;
    cin >> n;
    cin.ignore(1);

    char *str[n];

    for(int i = 0; i < n; i++)
    {
        str[i] = (char*)malloc(sizeof(char) * (100 + 1));
    }

    for(int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(str[i][0] > str[j][0])
            {
                char temp[strlen(str[i | j])];
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << str[i] << endl;
    }

    return 0;
}

void fillArray(int **p, int size)
{
    *p = (int*)malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++)
    {
        (*p)[i] = i;
    }
}

void printArray(int *p, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

void copy(int *a, int **b, int size)
{
    *b = (int*)malloc(sizeof(int) * (size-1));

    for(int i = 0, index = 0; i < size; i++)
    {
        if((i + 1) == (size + 1) / 2)
        {
            continue;
        }

        (*b)[index++] = a[i];
    }
}

int main12_12()
{
    int *arr = NULL;
    int *arr2 = NULL;
    int n;

    cin >> n;

    fillArray(&arr, n);
    copy(arr, &arr2, n);

    printArray(arr2, n - 1);

    return 0;
}

int main12_11()
{
    int *arr = (int*)malloc(sizeof(int) * 5);

    for(int i = 0; ; i++)
    {
        int arr1[i];
        cin >> arr1[i];

        if(arr1[i] <= 0)
        {
            break;
        }
        arr[i] = arr1[i];
        if(sizeof(arr) < sizeof(arr1[i]))
        {
            arr = (int*)realloc(arr, sizeof(int) * 1);
        }
    }
    for(int i = 0; arr[i]; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    free(arr);

    return 0;
}

int main12_10()
{
    int n;
    cin >> n;
    cin.ignore(1);

    char *str[n];

    for(int i = 0; i < n; i++)
    {
        str[i] = (char*)malloc(sizeof(char) * 100);
    }

    for(int i = 0; i < n; i++)
    {
        cin.getline(str[i], 101);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strlen(str[i]) < strlen(str[j]))
            {
                char temp[strlen(str[i | j])];
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << str[i] << endl;
    }

    free(str[n]);

    return 0; 
}

int main12_8()
{   
    int n;
    cin >> n;

    char *arr = (char*)malloc(sizeof(char) * n + 1);
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i - 1] == 'c' && arr[i] == 'a' && arr[i + 1] == 't')
        {
            count++;
        }
    }

    cout << count << endl;

    free(arr);

    return 0;
}

int main12_9()
{
    int n;
    cin >> n;
    cin.ignore(1);

    char *str[n];
    for(int i = 0; i < n; i++)
    {
        str[i] = (char*)malloc(sizeof(char) * 100);
    }
    char *min;
    for(int i = 0; i < n; i++)
    {
        cin.getline(str[i], 100);
    }
    min = str[0];
    for(int i = 0; i < n; i++)
    {
        if(strlen(min) > strlen(str[i]))
        {
            min = str[i];
        }
    }

    cout << min << endl;

    free(str[n]);

    return 0;
}

int main12_7()
{
    int n;
    cin >> n;
    int *arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    free(arr);

    return 0;
}

typedef struct
{
    char name[8];
    float korean, english, math;
    float aver;
} REsult;

void getResult(REsult *students, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> students[i].name >> students[i].korean >> students[i].english >> students[i].math;
        students[i].aver = (students[i].korean + students[i].english + students[i].math) / 3;
    }
}

void printResult(REsult *students, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(students[i].aver >= 90)
        {
            cout << students[i].name << " " << students[i].aver << " GREAT\n";
        }
        else if(students[i].aver < 90)
        {
            cout << students[i].name << " " << students[i].aver << " GREAT BAD\n";
        }
    }
}

int main12_6()
{
    int n;
    cin >> n;
    REsult *students = (REsult*)malloc(sizeof(REsult) * n);

    getResult(students, n);

    printResult(students, n);

    free(students);

    return 0;
}

int main12_5()
{
    int n;
    char a, b;
    cin >> n;
    cin.ignore(1);

    char *str = (char*)malloc(sizeof(char) * n + 1);

    cin.getline(str, n + 1);

    cin >> a >> b;
    int count1 = 0, count2 = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == a)
        {
            count1++;
        }
        else if(str[i] == b)
        {
            count2++;
        }
    }
    cout << count1 << " " << count2 << endl;

    free(str);

    return 0;
}

int main12_4()
{
    int n, m;
    cin >> n >> m;
    char **arr;
    arr = (char**)malloc(sizeof(char*) * (n * m));

    int b = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((b + 97) >= 97 && (b + 97) <= 122)
            {
                cout << (char)(b + 97) << " ";
            }
            else if((b + 97) > 122)
            {
                cout << (char)((b + 97) - (57 + 1)) << " ";
            }
            else if((b + 97) - 32 >= 91 && (b + 97) - 32 <= 96)
            {
                cout << (char)((b + 97) - 32) << " ";
            }
            else if((b + 97) - 32 > 96)
            {
                cout << (char)((b + 97) - 32) << " ";
            }
            b++;
        }
        cout << endl;
    }

    return 0;
}

int main12_3()
{
    int n;
    cin >> n;

    int *arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }    

    int del;
    cin >> del;

    arr = (int*)realloc(arr, sizeof(int) * (n - del));

    for(int i = 0; i < n - del; i++)
    {
        cout << arr[i] << endl;
    }  

    free(arr);
    arr = NULL;

    return 0;
}

int main12_2()
{
    int n; cin >> n;
    float *arr = (float*)malloc(sizeof(float) * n);
    float *pmax;
    for(float *p = arr; p < arr + n; p++)
    {
        cin >> *p;
    }
    for(float *p = arr; p < arr + n; p++)
    {
        if(*p > *pmax)
        {
            *pmax = *p;
        }
    }

    cout << *pmax << endl;

    free(arr);

    return 0;
}

int main12_1()
{
    int n, sum = 0, *psum = &sum;
    cin >> n;
    int *arr = NULL;

    arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        *psum += arr[i];
    }

    cout << *psum << endl;

    free(arr);

    return 0;
}

// Ch - 11

typedef struct
{
    int sex, weight, height;
} HANDSOME;

void getHandSome(HANDSOME student[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> student[i].sex >> student[i].weight >> student[i].height;
    }
}

void findHandSome(HANDSOME student[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(student[i].sex == 1)
        {
            cout << student[i].sex << " ";
            if(student[i].weight < 60)
            {
                cout << (student[i].weight < 60 ? 0 : 1) << " ";
                if(student[i].height < 165)
                {
                    cout << (student[i].height < 165 ? 0 : 1) << endl;
                }
                else if(student[i].height >= 165 && student[i].height < 175)
                {
                    cout << (student[i].height >= 165 && student[i].height < 175 ? 1 : 2) << endl;
                }
                else if(student[i].height >= 175)
                {
                    cout << (student[i].height >= 175 ? 2 : 3) << endl;
                }

            }
            else if(student[i].weight >= 60 && student[i].weight < 70)
            {
                cout << (student[i].weight >= 60 && student[i].weight < 70 ? 1 : 2) << " ";
                if(student[i].height < 165)
                {
                    cout << (student[i].height < 165 ? 3 : 4) << endl;
                }
                else if(student[i].height >= 165 && student[i].height < 175)
                {
                    cout << (student[i].height >= 165 && student[i].height < 175 ? 1 : 2) << endl;
                }
                else if(student[i].height >= 75)
                {
                    cout << (student[i].height >= 175 ? 1 : 2) << endl;
                }
            }
            else if(student[i].weight >= 70)
            {
                cout << (student[i].weight >= 70 ? 2 : 3) << " ";
                if(student[i].height < 165)
                {
                    cout << (student[i].height < 165 ? 2 : 3) << endl;
                }
                else if(student[i].height >= 165 && student[i].height < 175)
                {
                    cout << (student[i].height >= 165 && student[i].height < 175 ? 3 : 4) << endl;
                }
                else if(student[i].height >= 75)
                {
                    cout << (student[i].height >= 175 ? 1 : 2) << endl;
                }
            }
        }
        else if(student[i].sex == 2)
        {
            cout << student[i].sex << " ";
            if(student[i].weight < 50)
            {
                cout << (student[i].weight < 50 ? 0 : 1) << " ";
                if(student[i].height < 165)
                {
                    cout << (student[i].height < 165 ? 0 : 1) << endl;
                }
                else if(student[i].height >= 165 && student[i].height < 175)
                {
                    cout << (student[i].height >= 165 && student[i].height < 175 ? 1 : 2) << endl;
                }
                else if(student[i].height >= 175)
                {
                    cout << (student[i].height >= 175 ? 2 : 3) << endl;
                }

            }
            else if(student[i].weight >= 50 && student[i].weight < 60)
            {
                cout << (student[i].weight >= 50 && student[i].weight < 60 ? 1 : 2) << " ";
                if(student[i].height < 165)
                {
                    cout << (student[i].height < 165 ? 3 : 4) << endl;
                }
                else if(student[i].height >= 165 && student[i].height < 175)
                {
                    cout << (student[i].height >= 165 && student[i].height < 175 ? 1 : 2) << endl;
                }
                else if(student[i].height >= 75)
                {
                    cout << (student[i].height >= 175 ? 1 : 2) << endl;
                }
            }
            else if(student[i].weight >= 60)
            {
                cout << (student[i].weight >= 60 ? 2 : 1) << " ";
                if(student[i].height < 165)
                {
                    cout << (student[i].height < 165 ? 2 : 3) << endl;
                }
                else if(student[i].height >= 165 && student[i].height < 175)
                {
                    cout << (student[i].height >= 165 && student[i].height < 175 ? 3 : 4) << endl;
                }
                else if(student[i].height >= 75)
                {
                    cout << (student[i].height >= 175 ? 1 : 2) << endl;
                }
            }
        }
    }
}

int main11_11()
{
    int n;
    cin >> n;

    HANDSOME students[n];

    getHandSome(students, n);

    findHandSome(students, n);

    return 0;
}

typedef struct
{
    int max, min, otishOraligi, ballOraligi;
    char letter;
} EXResult;

EXResult getExStudent()
{
    EXResult temp;
    cin >> temp.max >> temp.min >> temp.otishOraligi;
    temp.ballOraligi = temp.max - temp.min;
    return temp;
}

void passorfail(EXResult *student)
{
    if(student->ballOraligi <= student->otishOraligi)
    {
        cout << student->ballOraligi << " " << (student->letter = 'P') << endl;
    }
    else if(student->ballOraligi > student->otishOraligi)
    {
        cout << student->otishOraligi - student->ballOraligi << " " << (student->letter = 'F') << endl;
    }
}

int main11_10()
{
    EXResult student = getExStudent();
    passorfail(&student);

    return 0;
}

typedef struct 
{
    double real, image;
} Complex;

Complex readComplex()
{
    Complex num;
    cin >> num.real >> num.image;
    return num;
}

Complex addComplex(Complex n1, Complex n2)
{
    Complex n3 = { n1.real + n2.real, n1.image + n2.image };
    return n3;
}

void printComplex(Complex *num)
{
    cout << num->real << " + " << num->image << "i" << endl;
}

int main11_9()
{
    Complex n1 = readComplex(), n2 = readComplex();

    Complex n3 = addComplex(n1, n2);
    printComplex(&n3);

    return 0;
}

typedef struct
{
    char name[9];
    double graid[3];
    double average;
} RESULT;

void readStudent(RESULT students[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> students[i].name;
        for(int j = 0; j < 3; j++)
        {
            cin >> students[i].graid[j];
            students[i].average += students[i].graid[j] / 3;
        }
    }
}

void printScore(RESULT students[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(students[i].average >= 90)
        {
            cout << students[i].name << " " << students[i].average << "A" << endl;
        }
        else if(students[i].average >= 80 && students[i].average < 90)
        {
            cout << students[i].name << " " << students[i].average << "B" << endl;
        }
        else if(students[i].average >= 70 && students[i].average < 80)
        {
            cout << students[i].name << " " << students[i].average << "C" << endl;
        }
        else
        {
            cout << students[i].name << " " << students[i].average << "F" << endl;
        }
    }
}

int main11_8()
{
    int n;
    cin >> n;
    RESULT students[n];

    readStudent(students, n);
    printScore(students, n);

    return 0;
}

typedef struct
{
    int num;
} Arr;

void readArr(Arr arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].num;
    }
}

void sortArr(Arr arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i].num < arr[j].num)
            {
                int temp = arr[i].num;
                arr[i].num = arr[j].num;
                arr[j].num = temp;
            }
        }
    }
}

void printArr(Arr arr[], int n)
{
    cout << arr[3].num << " " << arr[7].num << endl;
}

int main11_7()
{
    Arr arr[10];
    readArr(arr, 10);
    sortArr(arr, 10);
    printArr(arr, 10);

    return 0;
}

typedef struct
{
    char name[21];
    double average;
    double graid;
} Result;

int main11_6()
{
    int n;
    cin >> n;
    Result student[n][3];
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> student[i]->name;
        for(int j = 0; j < 3; j++)
        {
            cin >> student[i][j].graid;
            student[i]->average += student[i][j].graid / 3;
        }
    }

    float aver = (float)sum / n;

    for(int i = 0; i < n; i++)
    {
            if(student[i]->average >= 90)
            {
                cout << student[i]->name << " " << student[i]->average << "A" << endl;
            }   
            else if(student[i]->average >= 80 && student[i]->average < 90)
            {
                cout << student[i]->name << " " << student[i]->average << "B" << endl;
            }   
            else if(student[i]->average >= 70 && student[i]->average < 80)
            {
                cout << student[i]->name << " " << student[i]->average << "C" << endl;
            }   
            else
            {
                cout << student[i]->name << " " << student[i]->average << "F" << endl;
            }
    }

    return 0;
}

/*
typedef struct
{
    char* name;
    double* score;
    double aver;
} *STP, ST;

void readStudent(STP *students, int size)
{
    int sum = 0;
    if(students == NULL)
    {
        *students = (STP)malloc(sizeof(ST) * size);
    }
    for(int i = 0; i < size; i++)
    {
        char temp[101];
        cin >> temp;

        *students[i]->name = *(char*)malloc(sizeof(char) * (strlen(temp) + 1));

        strcpy(students[i]->name, temp);

        *students[i]->score = *(double*)malloc(sizeof(double) * 3);

        for(int j = 0; j < 3; j++)
        {
            cin >> *students[i][j].score;
            students[i][j].aver += *(students[i][j].score) / 3;
            if(students[i][j].aver >= 90)
            {
                cout << students[i][j].name << " " << students[i][j].aver << "A" << endl;
            }
            if(students[i][j].aver >= 80 && students[i][j].aver < 90)
            {
                cout << students[i][j].name << " " << students[i][j].aver << "C" << endl;
            }
            if(students[i][j].aver >= 70 && students[i][j].aver < 80)
            {
                cout << students[i][j].name << " " << students[i][j].aver << "B" << endl;
            }
            else
            {
                cout << students[i][j].name << " " << students[i][j].aver << "F" << endl;
            }
        }
    }
    
}

int main()
{
    int n;
    cin >> n;

    STP students = NULL;

    readStudent(&students, n);
    
    return 0;
}
*/

typedef struct
{
    int graid;
    char name[10];
} ExamResult_1;

void ExRes(ExamResult_1 *student, float aver)
{
    for(int i = 0; i < 5; i++)
    {
        if(student[i].graid < aver)
        {
            cout << student[i].name << endl;
        }
    }
}

int main11_5()
{
    ExamResult_1 student[5];
    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        cin >> student[i].name >> student[i].graid;
        sum += student[i].graid;
    }

    float aver = (float)sum / 5;

    ExRes(student, aver);
    

    return 0;
}


typedef struct
{
    int surat, mahraj;
} Franction;

Franction getFranction(Franction *F)
{
    cin >> F->surat >> F->mahraj;
    return *F;
}

void findFranction(Franction *f1, Franction *f2)
{
    if(f1->surat * f2->surat < f1->mahraj * f2->mahraj)
    {
        cout << f1->surat * f2->surat << "/" << f1->mahraj * f2->mahraj;
    }
    else if (f1->surat * f1->mahraj > f2->surat * f2->mahraj)
    {
        cout << f2->surat * f2->mahraj << "/" << f1->surat * f1->mahraj;
    }
    else if (f1->surat * f1->mahraj < f2->surat * f2->mahraj)
    {
        cout << f1->surat * f1->mahraj << "/" << f2->surat * f2->mahraj;
    }
    
}

int main11_4()
{
    Franction f1 = getFranction(&f1), f2 = getFranction(&f2);

    findFranction(&f1, &f2);


    return 0;
}

typedef struct
{
    char name[101];
    int graid;
} Student;

int main11_433()
{
    Student st1[5];
    int sum = 0;

    for(int i = 0; i < 5; i++)
    {
        cin >> st1[i].name >> st1[i].graid;
        sum += st1[i].graid;
    }

    float average = (float)sum / 5;

    for(int i = 0; i < 5; i++)
    {
        if(st1[i].graid < average)
        {
            cout << st1[i].name << endl;
        }
    }


    return 0;
}

typedef struct
{
    int hours, minute, second;
} TIME;

TIME getTime11_3(TIME *time)
{
    cin >> time->hours >> time->minute >> time->second;
    return *time;
}

TIME howTime11_3(TIME *time1, TIME *time2)
{
    TIME t1 = {time2->hours - time1->hours, time2->minute - time1->minute, time2->second - time1->second};

    if(time2->hours - time1->hours < 0)
    {
        t1.hours = 0;
    }
    else if(time2->minute - time1->minute < 0)
    {
        t1.hours -= 1;
        t1.minute = (time2->minute + 60) - time1->minute;
        if(time2->second - time1->second < 0)
        {
            t1.minute -= 1;
            t1.second = (time2->second + 60) - time1->second;
        }
    }

    return t1;
}

void printTime11_3(TIME *time)
{
    cout << time->hours << " " << time->minute << " " << time->second << endl;
}

int main446()
{
    TIME time1 = getTime11_3(&time1), time2 = getTime11_3(&time2);
    TIME time3 = howTime11_3(&time1, &time2);

    printTime11_3(&time3);

    return 0;
}

typedef struct
{
    int x, y, z;
} VECTOR;

VECTOR getVector11_2(VECTOR *V)
{
    cin >> V->x >> V->y >> V->z;
    return *V;
}

VECTOR multiplicationVector11_2(VECTOR *v1, VECTOR *v2)
{
    VECTOR v3 = { v1->x * v2->x, v1->y * v2->y, v1->z * v2->z };
    return v3;
}

void printVector11_2(VECTOR *v3)
{
    cout << v3->x << " " << v3->y << " " << v3->z << endl;
}

int sumOfVec11_2(VECTOR *v3)
{
    int sum = v3->x + v3->y + v3->z;
    return sum;
}

int main11_2()
{
    VECTOR v1 = getVector11_2(&v1), v2 = getVector11_2(&v2);

    VECTOR v3 = multiplicationVector11_2(&v1, &v2);
    int sum = sumOfVec11_2(&v3);

    printVector11_2(&v3);

    cout << sum << endl;

    return 0;
}

typedef struct
{
    int x, y, z;
} VECTOR_1;

VECTOR_1 getVector11_1()
{
    VECTOR_1 temp;
    cin >> temp.x >> temp.y >> temp.z;
    return temp;
}

// VECTOR getVector(VECTOR *v1)
// {
//     cin >> v1->x >> v1->y >> v1->z;
//     return *v1;
// }

VECTOR_1 addVector11_1(VECTOR_1 *v1, VECTOR_1 *v2)
{
    VECTOR_1 v3 = { v1->x + v2->x, v1->y + v2->y, v1->z + v2->z };
    return v3;
}

void printVector11_1(VECTOR_1 *v3)
{
    cout << v3->x << " " << v3->y << " " << v3->z << endl;;
}

int main11_1()
{
    VECTOR_1 v1 = getVector11_1(), v2 = getVector11_1();
    // VECTOR v1 = getVector(&v1), v2 = getVector(&v2);

    VECTOR_1 v3 = addVector11_1(&v1, &v2);

    printVector11_1(&v3);

    return 0;
}

// Ch-10

int len(char *str)
{
    int length = 0;
    while(str[length]) { length++; }
    return length;
}

int compare(char *a, char *b)
{
    while(*a == *b && *a) { a++; b++; }
    return *a == *b;
}

int contains(char *a, char *b)
{
    for(char *p = a; p <= a + len(a) - len(b); p++)
    {
        char temp[len(b)];
        strncpy(temp, p, len(b));
        temp[len(b)] = '\0';
        if(compare(temp, b))
        {
            return 1;
        }
    }
    return 0;
}

int indexOf(char *a, char *b)
{
    for(int i = 0; i <= len(a) - len(b); i++)
    {
        if(contains(&a[i], b))
        {
            return i;
        }
    }
    return -1;
}

int main10_11()
{
    int num;
    cin >> num;
    int n1 = num, x = 0;
    while(n1--)
    {
        x++;
    }

    int x1 = x;
    for(int i = 0; i < x; i++)
    {
        int a = pow(10, x1 - 1);
        switch(num / a)
        {
            case 0: break;
            case 1: cout << "one "; break;
            case 2: cout << "two "; break;
            case 3: cout << "three "; break;
            case 4: cout << "four "; break;
            case 5: cout << "five "; break;
            case 6: cout << "six "; break;
            case 7: cout << "seven "; break;
            case 8: cout << "eight "; break;
            case 9: cout << "nine "; break;
            default: break;
        }
        switch(x1)
        {
            case 2: cout << "TEN "; break;
            case 3: cout << "HUN "; break;
            case 4: cout << "THO "; break;
            default: break;
        }
        num =  num % a;
        x1--;
    }
  
    return 0;
}

int main10_10()
{
    char str1[101], str2[101];
    cin >> str1 >> str2;
    char *Str;

    if(len(str1) > len(str2))
    {
        Str = str1;
        strcat(Str, str2);
    }
    else if(len(str1) < len(str2))
    {
        Str = str2;
        strcat(Str, str1);
    }
    cout << Str << endl;

    return 0;
}

int main10_9()
{
    char str1[101], str2[101];
    cin.getline(str1, 100);
    cin.getline(str2, 100);

    int n1;
    cin >> n1;
    cin.ignore(1);
    int n2;
    cin >> n2;
    for(int i = 0; i < n1; i++)
    {
        cout << str1[i];
    }
    if(n2 == 0)
    {
        for(int i = 0; str2[i]; i++)
        {
            for(int j = i + 1; str2[j]; j++)
            {
                if(str2[i] > str2[j])
                {
                    char temp = str2[i];
                    str2[i] = str2[j];
                    str2[j] = temp;
                }
            }
        }
        cout << str2;
    }
    else if(n2 == 1)
    {
        for(int i = 0; str2[i]; i++)
        {
            for(int j = i + 1; str2[j]; j++)
            {
                if(str2[i] < str2[j])
                {
                    char temp = str2[i];
                    str2[i] = str2[j];
                    str2[j] = temp;
                }
            }
        }
        cout << str2;
    }

    for(int i = n1; str1[i]; i++)
    {
        cout << str1[i];
    }

    cout << endl;

    return 0;
}

int mainPolymorphism()
{
    int n1, n2;
    cin >> n1;
    cin.ignore(1);

    cin >> n2;

    char str[101][101];

    for(int i = 0; i < n1; i++)
    {
        cin.getline(str[i], 101);
    }

    int a = 1;

    for(int i = 1; i <= n1; i++)
    {
        a = (a + n2 - 1) % i + 1;
    }        


    cout << endl << str[a] << endl;

    return 0;
}

int main10_8()
{
    char str1[101], str2[101];
    cin.getline(str1, 100);
    cin.getline(str2, 100);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << str1[i];
    }

    cout << str2;

    for(int i = n; str1[i]; i++)
    {
        cout << str1[i];
    }

    cout << endl;    

    return 0;
}

int main10_7()
{
    int num;
    cin >> num;
    
    cin.ignore(1);

    char str[101][101];

    for(int i = 0; i < num; i++)
    {
        cin.getline(str[i], 100);
    }

    char *minStr = str[0];

    for(int i = 0; i < num; i++)
    {
        if(len(str[i]) < len(minStr))
        {
            minStr = str[i];
        }
    }

    cout << minStr << endl;
    
    return 0;
}

int countSubString10_6(char *a, char *b)
{
    int count = 0;
    for(char *p = a; p <= a + len(a) - len(b); p++)
    {
        if(contains(p, b))
        {
            count++;

            p = p + indexOf(p, b) + len(b) - 1;
        }
    }
    return count;
}

int main10_6_2()
{
    char str1[101], str2[101];
    cin.getline(str1, 100);
    cin.getline(str2, 100);

    cout << countSubString10_6(str1, str2) << endl;

    return 0;
}

// int main10_6_1()
// {
// 	char str1[101], str2[101];
//     cin.getline(str1, 100);
//     cin.getline(str2, 100);

//     int count = 0, len2 = len(str2);

//     for(int i = 0; str1[i]; i++)
//     {
//         for(int j = 0; str2[j]; j++)
//         {
//             int l2 = 1;
//             if(str1[i] == str2[j])
//             {
//                 bool before = false;
//                 for(int k = 1; k <= len2; k++)
//                 {
//                     if(!before)
//                     {
//                         if(str1[i + k] == str2[j + k])
//                         {
//                             l2++;
//                         }
//                     }
//                 }
//                 if(l2 == len2)
//                 {
//                     if(!before)
//                     {
//                         count++;
//                         if(len2 == 1)
//                         {
//                             i = i;
//                         }
//                         else if(len2 % 2 == 0)
//                         {
//                             i += len2;
//                         }
//                         else
//                         {
//                             i++;
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     cout << count << endl;

// 	return 0;
// }

int len10_5(char *str)
{
    int length = 0;
    while(str[length]) length++;
    return length;
}

int compare10_5(char *a, char *b)
{
    // bool thesame = true;
    // for(char *p = a; a[*p]; p++)
    // {
    //     if(a[*p] == b[*p])
    //     {
    //         thesame = false;
    //     }
    // }
    // return thesame;

    while(*a == *b && *a) { a++; b++; }
    return *a == *b;
}

int contains10_5(char *a, char *b)
{
    for(char *p = a; p <= a + len10_5(a) - len10_5(b); p++)
    {
        char temp[len10_5(b)];
        strncpy(temp, p, len10_5(b));
        temp[len10_5(b)] = '\0';

        if(compare10_5(temp, b))
        {
            return 1;
        }
    }
    return 0;
}

int main10_5()
{
    char str1[101], str2[81];
    cin.getline(str1, 100);
    cin.getline(str2, 80);

    cout << len10_5(str1) << " ";
    cout << contains10_5(str1, str2) << endl;

    return 0;
}

int len10_4(char *str)
{
    int length = 0;
    while(str[length]) { length++; } // <- once variant
    // for(int i = 0; str[i]; i++)
    // {
    //     length++; <- twice variant
    // }
    return length;
}

int theSame10_4_2(char *a, char *b)
{
    while(*a == *b && *a) { a++; b++; }

    return *a == *b;
}

int theSame10_4_1(char *a, char *b)
{
    bool thesame = false; // bool thesame = true;
    for(int i = 0; a[i]; i++)
    {
        if(a[i] == b[i]) // a[i] != b[i]
        {
            thesame = true; // thesame = false 
        }
    }
    return thesame;
}

int main10_4()
{
    char str1[101], str2[101];
    cin.getline(str1, 101);
    cin.getline(str2, 101);

    cout << len10_4(str1) << " ";
    cout << theSame10_4_2(str1, str2) << endl;

    return 0;
}


int main10_3() 
{
    char str[101];
    cin >> str;

    for(int i = 0; i < strlen(str); i++)
    {
        for(int count = 0, start = i; count < strlen(str); count++, start++)
        {
            cout << str[start % strlen(str)];
        }
        cout << endl;
    }

    return 0;
}

int main10_2()
{
    int num;
    cin >> num;
    
    char chNum[12];
    int i = 0;

    while(num)
    {
        chNum[i] = num % 10 + '0';
        num /= 10;
        i++;
    }
    // for(i = 0; num; num /= 10, i++)
    // {
    //     chNum[i] = num % 10 + '0';
    // }
    chNum[i] = '\0';

    cout << chNum << endl;

    return 0;
}

int isLower10_1(char str)
{
    return str >= 'a' && str <= 'z';
}

int main10_1()
{
    char str[21];
    cin >> str;

    for(int i = 0; i < strlen(str); i++)
    {
        if(isLower10_1(str[i]))
        {
            cout << str[i];
        }
    }

    cout << endl;

    return 0;
}

// String theme

int mainString_theme_4()
{
    char str1[20], str2[20];
    cin >> str1 >> str2;

    cout << strlen(str1) << " " << strlen(str2) << endl;

    cout << strcmp(str1, str2) << endl;
    char *str3 = strcat(str1, str2);

    cout << str3 << endl;

    return 0;
}

int mainString_theme_3()
{
    char arr[3][20] = { "Time is gold", "No pain no gain", "No sweat no sweet" };
    int count = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(arr[i][j] == 'a')
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

int mainString_theme_2()
{
    char arr[] = "To be, or not to be:that is the question";
    int count = 0;

    for(int i = 0; i < strlen(arr); i++)
    {
        if(arr[i] == 't')
        {
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}

int mainString_theme_1()
{
    char *name;
    cin >> *name;
    cout << name[0] << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << name[i];
    }
    cout << endl;

    return 0;
}

// ch-9

void addArray9_17(int *a1, int *a2, int size, int *a3)
{
    int sum = 0, *psum = 0;

    for(int *p = a1; p < a1 + size; p++)
    {
        for(int *q = a2; q < a2 + size; q++)
        {
            *psum = *p + *q;
        }
        cout << endl;
    }
}

int maindiagonal()
{
    int n, *pn = &n, m, *pm = &m;
    int arr1[50][50], arr3[50];
    cin >> *pn >> *pm;


    for(int p = 0; p < *pn; p++)
    {
        for(int q = 0; q < *pm; q++)
        {
            cin >> arr1[p][q];
        }
    }

    int sum = 0, *psum = &sum;
    
    for(int p = 0; p < *pn; p++)
    {
        for(int q = 0; q < *pn; q++)
        {
            if(p == q)
            {
               *psum += arr1[p][p];
            }
        }

    }
    cout << *psum << " ";

    // addArray9_17(arr1, arr2, *pn, arr3);


    return 0;
}

void userAlign9_16(int arr[], int *size, int *which)
{
    for(int *p = arr; p < arr + *size; p++)
    {
        for(int *q = p + 1; q < arr + *size; q++)
        {
            if(*which == 0)
            {
                if(*p > *q)
                {
                    int temp, *ptemp = &temp;
                    *ptemp = *p;
                    *p = *q;
                    *q = *ptemp;
                }
            }
            else if(*which == 1)
            {
                if(*p < *q)
                {
                    int temp, *ptemp = &temp;
                    *ptemp = *p;
                    *p = *q;
                    *q = *ptemp;
                }
            }
        }
    }
}

int main9_16()
{
    int arr[50];
    int n, *pn = &n, which, *pwhich = &which;
    cin >> *pn >> *pwhich;

    for(int *p = arr; p < arr + *pn; p++)
    {
        cin >> *p;
    }

    userAlign9_16(arr, &*pn, &*pwhich);

    for(int *p = arr; p < arr + *pn; p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}

void ABC9_15(int arr[], int size)
{
    for(int *p = arr; p < arr + 10 - 1; p++)
    {
        for(int *q = p + 1; q < arr + 10; q++)
        {
            if(*p < *q)
            {
                int temp, *ptemp = &temp;
                *ptemp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }
}

int main9_15()
{
    int arr[10];

    for(int *p = arr; p < arr + 10; p++)
    {
        cin >> *p;
    }

    ABC9_15(arr, 10);

    for(int *p = arr; p < arr + 10; p++)
    {
       cout << *p << " ";
    }

    cout << endl;

    return 0;
}

int arrsum9_14(int arr[], int *pn)
{
    int sum = 0, *psum = &sum;
    for(int *p = arr; p < arr + *pn; p++)
    {
        cin >> *p;
        *psum += *p;
    }
    return *psum;
}

int main9_14()
{
    int n, *pn = &n, arr[*pn];
    cin >> *pn;

    cout << arrsum9_14(arr, &*pn) << endl;

    return 0;
}

void strcopy9_13()
{
    char a[6], b[6];
    
    for(char *p = a; p < a + 6; p++)
    {
        cin >> *p;
        for(char *q = a; q <= p; q++)
        {
            b[*q] = *p;
        }
    }
    for(char *p = b; p < b + 6; p++)
    {
        cout << *p;
    }
    cout << endl;
}

int main9_13()
{
    strcopy9_13();

    return 0;
}

int findEven9_12(int *size)
{
    int arr[*size];
    int count = 0, *pcount = &count;
    for(int *p = arr; p < arr + *size; p++)
    {
        cin >> *p;
        if(*p % 2 == 0)
        {
            (*pcount)++;
        }
    }
    return *pcount;
}

int main9_12()
{
    int n, *pn = &n;
    cin >> *pn;

    cout << findEven9_12(&*pn) << endl;

    return 0;
}

void sum_p9_11(int *p)
{
    int a, b, *pa = &a, *pb = &b;
    cin >> *pa >> *pb;

    *p = *pa + *pb;
}

int main9_11()
{
    int sum = 0, *psum = &sum;
    sum_p9_11(&*psum);

    cout << *psum << endl;

    return 0;
}

void swap_p9_10(int *p1, int *p2)
{
    int temp, *ptemp = &temp;
    *ptemp = *p1;
    *p1 = *p2;
    *p2 = *ptemp;
}

int main9_10()
{
    int arr[50], n, *pn = &n;

    cin >> *pn;

    for(int *p = arr; p < arr + *pn; p++)
    {
        cin >> *p;
    }

    int a, b, *pa = &a, *pb = &b;
    cin >> *pa >> *pb;
    
    swap_p9_10(&arr[*pa], arr + *pb);

    for(int *p = arr; p < arr + *pn; p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}

int main9_9()
{
    int arr[50], n, *pn = &n;

    cin >> *pn;

    for(int *p = arr; p < arr + *pn; p++)
    {
        cin >> *p;
    }
    int count = 0, *pcount = &count;
    for(int *p = arr; p < arr + *pn; p++)
    {
        if(*p == 0)
        {
            break;
        }
        (*pcount)++;
    }
    
    cout << *pcount << endl;

    return 0;
}

int main9_8()
{
    int arr[5], ranks[5];

    for(int *p = arr; p < arr + 5; p++)
    {
        cin >> *p;
    }

    for(int *p = arr, *j = ranks; p < arr + 5; p++, j++)
    {
        int rank = 1, *prank = &rank;
        for(int *q = arr; q < arr + 5; q++)
        {
            if(*p < *q)
            {
                (*prank)++;
            }
        }
        *j = *prank;
        cout << *p << "=r" << *j << " ";
    }

    return 0;
}

// double findMedian(int arr[], int n)
// {
//     // First we sort the array
//     sort(arr, arr + n);
 
//     // check for even case
//     if (n % 2 != 0)
//     {
//         return arr[n / 2];
//     }
 
//     return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
// }
 
// // Driver program
// int main()
// {
//     int arr[3];
//     for(int *p = arr; p < arr + 3; p++)
//     {
//         cin >> *p;
//     }
//     int n = 3;
//     cout << findMedian(arr, n) << endl;
//     return 0;
// }

int main9_7_2()
{
    int arr[3];
    for(int *p = arr; p < arr + 3; p++)
    {
        cin >> *p;
    }
    vector <int> v2(arr, arr + 3); // copy of a2
    
    int len = v2.size(), *plen = &len;
    
    nth_element(v2.begin(), v2.begin() + len / 2, v2.end());

    int median = v2[len / 2], *pmedian = &median;

    cout << median << endl;
    return 0;
}

int main9_7_1()
{
    int arr[3];
    int max1, max2, *pmax1 = &max1, *pmax2 = &max2;

    for(int *p = arr; p < arr + 3; p++)
    {
        cin >> *p;
    }
    *pmax1 = *pmax2 = *arr;
    for(int *p = arr; p < arr + 3; p++)
    {
        *pmax2 = *p > *pmax2 ? *p : *pmax2;
        *pmax2 = *p > *pmax1 ? *pmax1 : *pmax2;
        *pmax1 = *p > *pmax1 ? *p : *pmax1;
    }

    cout << *pmax2 << endl;

    return 0;
}

int main9_6()
{
    char arr[10];
    
    for(char *p = arr; p < arr + 10; p++)
    {
        cin >> *p;
    }
    int max = 0, *pmax = &max;
    char maxC, *pmaxC = &maxC;
    for(char *p = arr; p < arr + 10; p++)
    {
        int count = 0, *pcount = &count;
        for(char *q = arr; q <= p; q++)
        {
            if(*p == *q)
            {
                (*pcount)++;
            }
        }
        if(*pmax < *pcount)
        {
            *pmax = *pcount;
            *pmaxC = *p;
        }
    }

    cout << *pmaxC << " " << *pmax << endl;

    return 0;
}

int main9_5()
{
    char arr[20], *p = arr;

    while(true)
    {
        cin >> *p;

        if(*p == '#')
        {
            break;
        }
        p++;
    }
    p -= 1;

    while(p >= arr)
    {
        cout << *p;
        p--;
    }
    cout << endl;
    
    return 0;
}

int main9_4()
{
    int n, *pn = &n;
    int arr[100];

    cin >> *pn;

    for(int *p = arr; p < arr + *pn; p++)
    {
        cin >> *p;
    }
    int min, max, *pmin = &min, *pmax = &max;
    max = min = *arr;
    for(int *p = arr + 1; p < arr + *pn; p++)
    {
        if(*p < *pmin)
        {
            *pmin = *p;
        }
        else if(*p > *pmax)
        {
            *pmax = *p;
        }
    }

    cout << *pmin << " " << *pmax << endl;

    return 0;
}

int main9_3()
{
    int n, index, *pn = &n, *pind = &index;
    int arr[100];

    cin >> *pn;

    for(int *p = arr; p < arr + *pn; p++)
    {
        cin >> *p;
    }

    cin >> *pind;

    cout << *(arr + *pind) << endl;
    
    return 0;
}

int main9_2()
{
    int n, m, *pn = &n, *pm = &m, sum = 0, *psum = &sum;
    cin >> *pn >> *pm;

    while(*pn <= *pm)
    {
        *psum += *pn;
        (*pn)++;
    }

    cout << *psum << endl;

    return 0;
}

int main9_1()
{
    int x, *px = &x;

    cin >> x >> *px;

    cout << *px << endl;

    return 0;
}

// Pointer theme

int mainPointer_theme_4()
{
    int arr1[5] = { 4, 5, 6, 7, 8 }, arr2[5] = { 1, 3, 5, 7, 9 }, arr3[5] = { 0, 2, 4, 6, 8 };
    int *p[3];
    p[0] = arr1;
    p[1] = arr2;
    p[2] = arr3;;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << *p[i] + j << " ";
        }
        cout << endl;
    }
    return 0;
}

int mainPointer_theme_3()
{
    int arr[10] = {1,2,3,4,5};
    for(int *p = arr; p; p++)
    {
        cout << *p << " ";
    }

    return 0;
}

int mainPointer_theme_2()
{
    int arr[5] = {1,2,3,4,5};
    int *p1 = &arr[1], *p2 = &arr[4];

    cout << p1 << " " << p2 << endl;;

    cout << (*p1 > *p2) << " " << (p1 < p2) << endl;

    return 0;
}

int mainPointer_theme_1()
{
    int arr[10] = {1,2,3,4,5};
    for(int i = 0; i < 10; i++)
    {
        int *p = &arr[i];
        cout << *p << " ";
    }

    return 0;
}
