#include <bits/stdc++.h>
#include <random>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class counterinfo{
public:
	int counternumber;
	int customerno;
	float depttimeallcurrcustomer;
	counterinfo(int counternumber,int customerno,float depttimeallcurrcustomer){
		this->counternumber=counternumber;
		this->customerno=customerno;
		this->depttimeallcurrcustomer=depttimeallcurrcustomer;
	}
};

class customernode{
public:
	int counterno;
	float arrivtime;
	float depttime;
	customernode(int counterno,float arrivtime,float depttime){
		this->counterno=counterno;
		this->arrivtime=arrivtime;
		this->depttime=depttime;
	}
};
class heap1 {
	vector<counterinfo*> data;
	public:

	heap1() {
		data.push_back(NULL);

	}

	int size() {
		return data.size() - 1;
	}

	bool isEmpty() {
		return size() == 0;
	}

	void removeMin() {
		if (isEmpty()) {
			throw "Empty Heap Error";
		}
		data[1] = data[data.size() - 1];
		data.pop_back();
		int currentIndex = 1;
		int leftIndex = 2*currentIndex;
		int rightIndex = 2*currentIndex + 1;
		while (leftIndex < data.size()) {
			int minIndex = currentIndex;
			if (data[leftIndex]->customerno < data[minIndex]->customerno) {
				minIndex = leftIndex;
			}

			if (rightIndex < data.size() &&
					data[rightIndex]->customerno < data[minIndex]->customerno) {
				minIndex = rightIndex;
			}
			if (minIndex == currentIndex) {
				break;
			} else {
				counterinfo* temp = data[minIndex];
				data[minIndex] = data[currentIndex];
				data[currentIndex] = temp;
				currentIndex = minIndex;
				leftIndex = 2*currentIndex;
				rightIndex = 2*currentIndex + 1;
			}
		}
	}

	counterinfo* displayroot() {
		if (isEmpty()) {
			throw "Empty Heap Error";
		}
		return data[1];
	}

	counterinfo* search(int counter){
		for(int i=1;i<data.size();i++){
			if(data[i]->counternumber==counter){
				return data[i];
			}
		}
		return NULL;
	}

	void insert(counterinfo* next) {
		data.push_back(next);
		int childIndex = data.size() - 1;
		int parentIndex = childIndex/2;
		while (childIndex != 1) {
			if (data[childIndex]->customerno >= data[parentIndex]->customerno) {
				break;
			} else {
				counterinfo* child =  data[childIndex];
				data[childIndex] = data[parentIndex];
				data[parentIndex] = child;
				childIndex = parentIndex;
				parentIndex = childIndex/2;
			}
		}
	}
	void heapify(){
		int currentIndex = 1;
		int leftIndex = 2*currentIndex;
		int rightIndex = 2*currentIndex + 1;
		while (leftIndex < data.size()) {
			int minIndex = currentIndex;
			if (data[leftIndex]->customerno < data[minIndex]->customerno) {
				minIndex = leftIndex;
			}

			if (rightIndex < data.size() &&
					data[rightIndex]->customerno < data[minIndex]->customerno) {
				minIndex = rightIndex;
			}
			if (minIndex == currentIndex) {
				break;
			} else {
				counterinfo* temp = data[minIndex];
				data[minIndex] = data[currentIndex];
				data[currentIndex] = temp;
				currentIndex = minIndex;
				leftIndex = 2*currentIndex;
				rightIndex = 2*currentIndex + 1;
			}
		}
	}

	void heapifydel(int counter){
		int childIndex=1;
		int parentIndex=0;
		for(int i=1;i<data.size();i++){
			if(data[i]->counternumber==counter){
				childIndex=i;
				parentIndex=childIndex/2;
			}
		}
		while (childIndex != 1) {
			if (data[childIndex]->customerno >= data[parentIndex]->customerno) {
				break;
			} else {
				counterinfo* child =  data[childIndex];
				data[childIndex] = data[parentIndex];
				data[parentIndex] = child;
				childIndex = parentIndex;
				parentIndex = childIndex/2;
			}
		}
	}
};


class heap2 {
	vector<customernode*> data;
	public:

	heap2() {
		data.push_back(NULL);

	}

	int size() {
		return data.size() - 1;
	}

	bool isEmpty() {
		return size() == 0;
	}

	void removeMin() {
		if (isEmpty()) {
			throw "Empty Heap Error";
		}
		data[1] = data[data.size() - 1];
		data.pop_back();
		int currentIndex = 1;
		int leftIndex = 2*currentIndex;
		int rightIndex = 2*currentIndex + 1;
		while (leftIndex < data.size()) {
			int minIndex = currentIndex;
			if (data[leftIndex]->depttime < data[minIndex]->depttime) {
				minIndex = leftIndex;
			}

			if (rightIndex < data.size() &&
					data[rightIndex]->depttime < data[minIndex]->depttime) {
				minIndex = rightIndex;
			}
			if (minIndex == currentIndex) {
				break;
			} else {
				customernode* temp = data[minIndex];
				data[minIndex] = data[currentIndex];
				data[currentIndex] = temp;
				currentIndex = minIndex;
				leftIndex = 2*currentIndex;
				rightIndex = 2*currentIndex + 1;
			}
		}
	}

	customernode* displayroot() {
		if (isEmpty()) {
			throw "Empty Heap Error";
		}

		return data[1];
	}

	void insert(customernode* next) {
		data.push_back(next);
		int childIndex = data.size() - 1;
		int parentIndex = childIndex/2;
		while (childIndex != 1) {
			if (data[childIndex]->depttime >= data[parentIndex]->depttime) {
				break;
			} else {
				customernode* child =  data[childIndex];
				data[childIndex] = data[parentIndex];
				data[parentIndex] = child;
				childIndex = parentIndex;
				parentIndex = childIndex/2;
			}
		}
	}

};



// create random no. that are uniformly distributed
float randomizedArr(float r)
{

    float m=1/r;
    random_device rd;  //device used to generate random no.
    minstd_rand gen(rd()); // engine used to generate random no.
    uniform_real_distribution<float> dis{0,m};

        return dis(gen);
}
float randomizedService(float m,float v)
{
    random_device rd;
    minstd_rand gen(rd());
    uniform_real_distribution<float> dis{m-v,m+v};

        return dis(gen);


}

float insertion(float arrivaltime,float servicetime,heap1& h1,heap2& h2,vector<queue<float>*>& arr ,float globaltime){
	int currcounter=h1.displayroot()->counternumber;
	float currdeparttime=0,currwaitingtime=0;
	h1.displayroot()->customerno++;
	if(arr[currcounter-1]->empty()){
		currwaitingtime=0;
		currdeparttime=servicetime+arrivaltime;
		arr[currcounter-1]->push(arrivaltime);
	}
	else{
		currdeparttime =h1.displayroot()->depttimeallcurrcustomer - (arrivaltime-arr[currcounter-1]->front())+servicetime + arrivaltime;
		currwaitingtime=h1.displayroot()->depttimeallcurrcustomer - (arrivaltime-arr[currcounter-1]->front());
		arr[currcounter-1]->push(arrivaltime);
	}
	h1.displayroot()->depttimeallcurrcustomer=h1.displayroot()->depttimeallcurrcustomer+servicetime;
	h1.heapify();
	customernode* newnode=new customernode(currcounter,arrivaltime,currdeparttime);
	h2.insert(newnode);
	return currwaitingtime;
}

void deletion(heap1& h1,heap2& h2,vector<queue<float>*>& arr ,float globaltime){
	int currcounter=h2.displayroot()->counterno;

	counterinfo* temp=h1.search(currcounter);
	temp->customerno--;
	float store=arr[currcounter-1]->front();
	temp->depttimeallcurrcustomer=temp->depttimeallcurrcustomer-(globaltime-store);
	arr[currcounter-1]->pop();
	float difference=globaltime-arr[currcounter-1]->front();
	temp->depttimeallcurrcustomer=temp->depttimeallcurrcustomer + difference;
	h1.heapifydel(currcounter);
	//cout<<h2.displayroot()->counterno<<endl;
	h2.removeMin();
	//cout<<h2.displayroot()->counterno<<endl;
}

int main() {

	int k,n;
	float m,v,r;
	cin>>r>>m>>v>>k>>n;
	heap1 h1;
	for (int i = 0; i < k; i++) {
		counterinfo *newnode=new counterinfo(i+1,0,0);
		h1.insert(newnode);
	}
	heap2 h2;
	vector<queue<float>*>arr;
	for(int i=0;i<k;i++){
		queue<float> * q=new queue<float>;
		arr.push_back(q);
	}
	float waitingtime=0;
	float globaltime=0;
	float arrivaltime=0;
	float*servicearr=new float [n];
	float*randomarr=new float [n];
	for(int i=0;i<n;i++){
		float servicetime=randomizedService(m,v);
		servicearr[i]=servicetime;
		waitingtime=waitingtime+insertion(arrivaltime,servicetime,h1,h2,arr,globaltime);
		float randomnumber=randomizedArr(r);
		randomarr[i]=randomnumber;
		arrivaltime=arrivaltime+randomnumber;
		globaltime=arrivaltime;
		if(h2.displayroot()->depttime<globaltime){
			deletion(h1,h2,arr,globaltime);
		}
	}

	double averagewaitingtime=(double)waitingtime/n;
	for(int i=0;i<n;i++){
		cout<<servicearr[i]<<" ";
	}
	cout<<endl;
	cout<<averagewaitingtime<<endl;

}

