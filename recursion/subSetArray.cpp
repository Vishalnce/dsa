 #include <iostream>

using namespace std;

// importanta question 

void print(int b[10][10], int totalRows) {

    for(int i = 0; i < totalRows; i++) {

        int size = b[i][0];

        cout << "{ ";

        for(int j = 1; j <= size; j++) {
            cout << b[i][j] << " ";
        }

        cout << "}" << endl;
    }
}


int  sub(int a[],int n,int b[10][10]){

    if(n == 0){
        b[0][0] = 0;  
        return 1;      
    }

  int temp =   sub(a+1,n-1,b);

  for(int i =temp;i<2*temp;i++){

    int oldRowIndex = i-temp;

    int loop = b[oldRowIndex][0];

    b[i][0] = loop + 1;
    b[i][1]=a[0];

    for(int j =1;j<=loop;j++){

     
      b[i][j+1]=b[oldRowIndex][j];

    }


  }

    


  return temp*2;

}

int main(){


  int a[] = {1,2,3,4};

  int size = sizeof(a)/ sizeof(int);

  int b[10][10] = {0};

  int g = sub(a,size,b);


  print(b,10);

  return 0;
}
