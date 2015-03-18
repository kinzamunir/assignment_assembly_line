
using namespace std;


void FastWay(int *a1, int *a2, int *t1, int *t2, int e1, int e2, int x1, int x2, int *f1, int *f2, int *L1, int *L2, int &L, int length)
{
	//adding the time for entering the lanes
	f1[1] = e1 + a1[1];
	f2[1] = e2 + a2[1];

	//calcultaing the path taking less time in processing in the stations.
	for (int j = 2; j < length; j++){
		//comparing which path take less time in reaching a particular station in lane 1. 
		if (f1[j - 1] + a1[j] <= f2[j - 1] + t2[j - 1] + a1[j])
		{
			f1[j] = f1[j - 1] + a1[j];
			L1[j] = 1; //storing the path taken.
		}
		else
		{
			f1[j] = f2[j - 1] + t2[j - 1] + a1[j];
			L1[j] = 2;
		}
		//comparing which path take less time in reaching a particular station in lane 2.
		if (f2[j - 1] + a2[j] <= f1[j - 1] + t1[j - 1] + a2[j])
		{

			f2[j] = f2[j - 1] + a2[j];
			L2[j] = 2;   //storing the path taken.
		}
		else
		{
			f2[j] = f1[j - 1] + t1[j - 1] + a2[j];
			L2[j] = 1;
		}

	}
	//determining the shortest time to exit the lane.
	if (f1[length - 1] + x1 <= f2[length - 1] + x2){

		f1[length] = f1[length - 1] + x1;
		L = 1;
	}
	else
	{
		f1[length] = f2[length - 1] + x2;
		L = 2;
	}

}
//  
void lane(int *L1, int *L2, int L, int length, int *f1)
{
	int i = L;
	
	cout << "Station : " << length << " line: " << i << endl;
	int j;
	//printing the station and lines used.
	for (j = length; j >= 2; j--)
	{
		if (i == 1)
		{
			i = L1[j];
		}
		else
		{
			i = L2[j];
		}
		cout << "Station : " << j - 1 << " line: " << i << endl;
	}
	cout << "The time using the fastest route is : " << f1[length + 1] << endl << endl;


}