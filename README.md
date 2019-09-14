# algorithm

## StudyLog

### 0914 - priority_queue

MST, LCA풀기위해서 pq를 이용하려고 함.
cmp 함수를 이용하기 위해서는 

```

struct cmp{
	bool operator()(Edge a, Edge b){
		return a.w > b.w;
	}
};

priority_queue <Edge, vector<Edge>, cmp> edgeVec;

```

위와 같은 식으로 선언해야함.

Vector의 cmp는 struct 를 안만들어도 되는걸로 알고있음.

오랜만에 알고리즘 공부하면서 나중에 다시 볼 때 이해할 수 있는 문서를 만드는게 목표!

