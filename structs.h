#ifndef _structs_h
#define _structs_h

#include "priority_queue.h"

typedef struct
{
     int cityID;
     int weight;
} city_weight_pair;

typedef enum
{
     QUEUED = 1,
     WORKING,
     FINISHED
} task_status;

typedef enum
{
     INIT_REQUEST = 1,
     REQUEST,
     COMPLETE,
     SELF,
} tsp_msg_type;


typedef struct
{
     int upstream_proposed_tour[MAX_TOUR_LENGTH];
     heap_t* downstream_pq;
     int tour_weight;
     int best_downstream_tour[MAX_TOUR_LENGTH];
     int best_down_weight;
     tw_lpid sender;
     tw_stime key;
     task_status status;
} task;


//TODO order the declarations to optimize memory usage
typedef struct
{
     city_weight_pair* incomingCityWeightPairs;
     city_weight_pair* outgoingCityWeightPairs;
     int min_downstream_complete_path[MAX_TOUR_LENGTH];
     heap_t* downstream_pq;
     task upstream_req_q[REQ_Q_MAX_SIZE];
     task active_task;
     // task requests_made[NUM_ACTIVE_REQ_PN];
     int num_tasks_working;

     // heap_t* upstream_req_pq;
     int num_upstream_requests;
     int self_place;
     int self_city;
     int rng_count;
     int min_downstream_weight;
     int num_incoming_neighbors;
     int num_outgoing_neighbors;
     int is_all_downstream_complete;
     int is_working;
     int num_req_sent;
     int num_complete_tours;
} tsp_actor_state;


typedef struct
{
     union{
          int upstream_proposed_tour[MAX_TOUR_LENGTH]; //defined if messType == TOUR
          int downstream_min_path[MAX_TOUR_LENGTH]; //defined if messType == COMPLETE
     } tour_dat; //For simplicity of understanding
     tw_stime key;
     int tour_weight;
     int downstream_weight;
     tw_lpid sender;
     tsp_msg_type messType;
     int saved_rng_count;
     // tsp_actor_state saved_state;
} tsp_mess;


#endif
