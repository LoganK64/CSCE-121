using namespace std;

struct queue_t;

queue_t * createQueue();

void destryQueue();

void push_front(queue_t*,float);

void push_back(queue_t*,float);

float pop_front(queue_t*);

float pop_back(queue_t*);

float peek_front(queue_t*);

float peek_back(queue_t*);