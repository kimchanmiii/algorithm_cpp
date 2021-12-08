#include <iostream>
using namespace std;

#define MAX 100000
int maxSize, minSize;
 
void maxHeap(unsigned long long max[], int a){
	int r, l;
	int largest;
	unsigned long long tmp;
 
	l=2*a;
	r=2*a+1;
	
	if(l<=maxSize && max[l]>max[a]){
		largest=l;
	}
	else{
		largest=a;
	}
	if(r<=maxSize && max[r]>max[largest]){
		largest=r;
	}
	if(largest!=a){
		tmp=max[a];
		max[a]=max[largest];
		max[largest]=tmp;
		
		maxHeap(max, largest);
	}
}

int deleteMaxHeap(unsigned long long max[]){
	unsigned long long result;
	
	result=max[1];
	
	max[1]=max[maxSize];
	maxSize--;
	
	maxHeap(max, 1);

	return result;
}

void minHeap(unsigned long long min[], int a){
	int r, l;
	int smallest;
	unsigned long long tmp;
	
	l=2*a;
	r=2*a+1;
	
	if(l<=minSize && min[l]<min[a]){
		smallest=l;
	}
	else{
		smallest=a;
	}
	if(r<=minSize && min[r]<min[smallest]){
		smallest=r;
	}
	if(smallest!=a){
		tmp=min[a];
		min[a]=min[smallest];
		min[smallest]=tmp;
		
		minHeap(min, smallest);
	}
}

int deleteMinHeap(unsigned long long min[]){
	unsigned long long result;
	
	result=min[1];
	min[1]=min[minSize];
	minSize--;
	
	minHeap(min, 1);

	return result;
}

void makeMax(unsigned long long max[]){
	unsigned long long tmp;
	int i;
	
	i=maxSize;
	
	while(max[i]>max[i/2]){
		tmp=max[i];
		max[i]=max[i/2];
		max[i/2]=tmp;
		
		if(i/2==1){
			break;
		} 
		else{
			i=i/2;
		}
	}
}
void makeMin(unsigned long long min[]){
	unsigned long long tmp;
	int i;
	
	i=minSize;
	
	while(min[i]<min[i/2]){
		tmp=min[i];
		min[i]=min[i/2];
		min[i/2]=tmp;
		
		if(i/2==1){
			break;
		} 
		else{
			i=i/2;
		}
	}
}

int main(){
	int t;
	int n;
	unsigned long long k, mid;
	int i, j, a;
	unsigned long long sum;
	unsigned long long max[MAX]={0,}, min[MAX]={0,};
	unsigned long long tmp;
	int tmpMid;
	
	std::cin >> t;
	
	for(i=0; i<t; i++){
		std::cin >> n;
		
		sum=0;
		maxSize=0;
		minSize=0;
				
		for(j=1; j<=n; j++){
			std::cin >> k;
			
			//첫번째 입력받는 수 
			if(j==1){
				maxSize++;
				max[maxSize]=k;
				mid=k;
			}
			else{
				//중앙값보다 작거나 같은 수 
				if(k<=mid){
					//maxHeap으로 넣음 
					maxSize++;
					max[maxSize]=k;
					
					//maxHeap의 조건을 만족시키게 함					
					if(max[maxSize]>max[maxSize/2]){
						makeMax(max);
					}
				}
				//중앙값보다 큰수 
				else{
					//minHeap으로 넣음 
					minSize++;
					min[minSize]=k;
					
					//minHeap의 조건을 만족시키게 함
					if(min[minSize]<min[minSize/2]){
						makeMin(min);
					}
				}
				
				//maxHeap과 minHeap의 벨런스를 맞춤 
				//홀수번째 숫자 -> maxHeap이 하나 더 많아야 함 
				if(j%2!=0){
					if(maxSize<=minSize){
						maxSize++;
						max[maxSize]=deleteMinHeap(min);
						
						//maxHeap의 조건을 만족시키게 함					
						if(max[maxSize]>max[maxSize/2]){
							makeMax(max);
						}
					}
				}
				//짝수번쨰 숫자-> 두 Heap이 같아야 함 
				else{
					if(maxSize<minSize){
						maxSize++;
						max[maxSize]=deleteMinHeap(min);
						
						//maxHeap의 조건을 만족시키게 함					
						if(max[maxSize]>max[maxSize/2]){
							makeMax(max);
						}
					}
					else if(maxSize>minSize){
						minSize++;
						min[minSize]=deleteMaxHeap(max);
						
						//minHeap의 조건을 만족시키게 함
						if(min[minSize]<min[minSize/2]){
							makeMin(min);
						}
					}
				}
				//홀수번째 숫자에서의 중앙값은 maxHeap의 root 
				if(j%2!=0){
					mid=max[1];
				}
				//짝수번째 숫자에서의 중앙값은 두 Heap의 평균 
				else{
					mid=(max[1]+min[1])/2;
				}
			}
			
			tmpMid=mid%10;
			sum+=tmpMid;
			sum%=10;
		}
		
		std::cout << sum << endl;
	}

	return 0;
}
