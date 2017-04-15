#include<iostream>

using namespace std;

int main(){
	cout<<"Please input the size of your Gather..."<<endl;
	int size=0;
	cin>>size;
	cout<<"The size of your Gather is "<<size<<"."<<endl;
	int *A = new int[size];
	cout<<endl;

	cout<<"Please input the elements of your Gather..."<<endl;
	bool Gather_legal = true;
	do{
		for(int i=0; i<size; i++)
			cin>>A[i];
		for(int i=0; i<size; i++){
			for(int j=i+1; j<size; j++)
				if(A[i]==A[j]){
					Gather_legal = false;
					break;
				}else
					Gather_legal = true;
			if(Gather_legal == false)
				break;
		}

		if(Gather_legal == false){
			cout<<"Your can't input the same elements in your Gather!"<<endl;
			cout<<"Please re-input  elements..."<<endl;
		}
	}while(Gather_legal == false);
	
	cout<<"Your Gather is"<<endl;
	for(int i=0; i<size; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	cout<<"----------------------------------------------------------"<<endl;

	int sizeR=0;
	int R[20][20]={0};
	cout<<"Please input the size of your Result Gather"<<endl;
	cin >> sizeR;
	if(sizeR>20)
		cout<<"My sortware can not do your work!"<<endl;
	else{
		for(int i=0; i<sizeR; i++){
			int Rx=0,Ry=0;
		    cout<<"Please input X Y of your Group "<<i+1<<endl;

			bool Rx_legal = false, Ry_legal = false;
		    do{
				cin>>Rx>>Ry;
				for(int j=0; j<size; j++)
					if(A[j]==Rx){
						Rx_legal = true;
						break;
					}else
						Rx_legal = false;
				if(Rx_legal == true)
					for(int j=0; j<size; j++)
						if(A[j]==Ry){
							Ry_legal = true;
							break;
						}else
							Ry_legal = false;

					   
				if(Rx_legal == false || Ry_legal == false){
					cout<<"Your XY can't have the element which isn't in your Gather!"<<endl;
					cout<<"Please re-input your X Y of your Group "<<i+1<<endl;
				}

			}while(Rx_legal == false || Ry_legal == false);

			int x=0, y=0;
			for(int i=0; i<size; i++){
				if(Rx==A[i])
					x=i;
			}
			for(int i=0; i<size; i++){
				if(Ry == A[i])
					y=i;
			}
	
			R[x][y]=1;
		}
		bool self_converse = true;  //自反性判断
		for(int i=0; i<size; i++){
				if(R[i][i] != 1)
					self_converse = false;
			}
         if(self_converse == true)
			 cout<<"具有";
		 else
			 cout<<"不具有";
		 cout<<"自反性"<<endl;

        bool irreflexive = true; //反自反性判断
	 	for(int i=0; i<size; i++){
				if(R[i][i] != 0)
					irreflexive = false;
			}
         if(irreflexive == true)
			 cout<<"具有";
		 else
			 cout<<"不具有";
		 cout<<"反自反性"<<endl;

	    bool symmetric = true;  //对称性判断
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++){
				if(R[i][j] != R[j][i])
					symmetric =false;
			}
         if(symmetric == true)
			 cout<<"具有";
		 else
			 cout<<"不具有";
		 cout<<"对称性"<<endl;
		 
        bool antisymmetry = true; //反对称性判断
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++){
				if(i != j)
					if(R[i][j]*R[j][i] != 0)
						antisymmetry = false;
			}
         if(antisymmetry == true)
			 cout<<"具有";
		 else
			 cout<<"不具有";
		 cout<<"反对称性"<<endl;

        bool transitivity = true; //传递性判断
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++)
				for(int k=0; k<size; k++){
					if(R[i][k]*R[k][j] == 1)
						if(R[i][j] != 1)
							transitivity = false;
				}
         if(transitivity == true)
			 cout<<"具有";
		 else
			 cout<<"不具有";
		 cout<<"传递性"<<endl;
	}

    delete A;

	system("pause");
	return 0;
}