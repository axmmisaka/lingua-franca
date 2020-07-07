// Code generated by the Lingua Franca compiler from file:
// /home/soroosh/lingua-franca/.experimental/test/CCpp/SetArray.lf
#include "ccpptarget.h"
#define NUMBER_OF_FEDERATES 1
// =============== START reactor class Source
typedef struct {
    int* value;
    bool is_present;
    int num_destinations;
    token_t* token;
    int length;
} source_out_t;
typedef struct {
    source_out_t __out;
    reaction_t ___reaction_0;
    bool* __reaction_0_outputs_are_present[1];
    int __reaction_0_num_outputs;
    trigger_t** __reaction_0_triggers[1];
    int __reaction_0_triggered_sizes[1];
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} source_self_t;
void sourcereaction_function_0(void* instance_args) {
    source_self_t* self = (source_self_t*)instance_args;
    template_input_output_port_with_token_struct<int*> * out = (template_input_output_port_with_token_struct<int*> *)&self->__out;
    // Dynamically allocate an output array of length 3.
    int* array = new int[3];
    SET_ARRAY(out, array, sizeof(int), 3);
    
    // Above allocates the array, which then must be populated.
    out->value[0] = 0;
    out->value[1] = 1;
    out->value[2] = 2;
        
}
source_self_t* new_Source() {
    source_self_t* self = (source_self_t*)calloc(1, sizeof(source_self_t));
    self->__reaction_0_outputs_are_present[0] = &self->__out.is_present;
    self->__reaction_0_num_outputs = 1;
    self->___reaction_0.function = sourcereaction_function_0;
    self->___reaction_0.self = self;
    self->___reaction_0.num_outputs = 1;
    self->___reaction_0.output_produced = self->__reaction_0_outputs_are_present;
    self->___reaction_0.triggered_sizes = self->__reaction_0_triggered_sizes;
    self->___reaction_0.triggers = self->__reaction_0_triggers;
    self->___reaction_0.deadline_violation_handler = NULL;
    self->___startup.scheduled = NEVER;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = true;
    return self;
}
// =============== END reactor class Source

// =============== START reactor class Print
typedef struct {
    int* value;
    bool is_present;
    int num_destinations;
    token_t* token;
    int length;
} print_in_t;
typedef struct {
    int scale;
    print_in_t* __in;
    reaction_t ___reaction_0;
    bool* __reaction_0_outputs_are_present[0];
    int __reaction_0_num_outputs;
    trigger_t** __reaction_0_triggers[0];
    int __reaction_0_triggered_sizes[0];
    trigger_t ___in;
    reaction_t* ___in_reactions[1];
} print_self_t;
void printreaction_function_0(void* instance_args) {
    print_self_t* self = (print_self_t*)instance_args;
    print_in_t* in = self->__in;
    if (in->is_present) {
        in->length = in->token->length;
        in->value = (int*)in->token->value;
    } else {
        in->length = 0;
    }
    int in_width = -2;
    int count = 0;       // For testing.
    bool failed = false; // For testing.
    printf("Received: [");
    for (int i = 0; i < in->length; i++) {
        if (i > 0) printf(", ");
        printf("%d", in->value[i]);
        // For testing, check whether values match expectation.
        if (in->value[i] != self->scale * count) {
            failed = true;
        }
        count++;         // For testing.
    }
    printf("]\n");
    if (failed) {
        printf("ERROR: Value received by Print does not match expectation!\n");
        exit(1);
    }
        
}
print_self_t* new_Print() {
    print_self_t* self = (print_self_t*)calloc(1, sizeof(print_self_t));
    self->__reaction_0_num_outputs = 0;
    self->___reaction_0.function = printreaction_function_0;
    self->___reaction_0.self = self;
    self->___reaction_0.num_outputs = 0;
    self->___reaction_0.output_produced = self->__reaction_0_outputs_are_present;
    self->___reaction_0.triggered_sizes = self->__reaction_0_triggered_sizes;
    self->___reaction_0.triggers = self->__reaction_0_triggers;
    self->___reaction_0.deadline_violation_handler = NULL;
    self->___in.scheduled = NEVER;
    self->___in_reactions[0] = &self->___reaction_0;
    self->___in.reactions = &self->___in_reactions[0];
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(int);
    return self;
}
// =============== END reactor class Print

// =============== START reactor class DelayArray
typedef struct {
    bool hasContents;
} delayarray_self_t;
delayarray_self_t* new_DelayArray() {
    delayarray_self_t* self = (delayarray_self_t*)calloc(1, sizeof(delayarray_self_t));
    return self;
}
// =============== END reactor class DelayArray

void __set_default_command_line_options() {
}
// Array of pointers to timer triggers to start the timers in __start_timers().
trigger_t* __timer_triggers[1];
int __timer_triggers_size = 1;
// Array of pointers to shutdown triggers.
trigger_t** __shutdown_triggers = NULL;
int __shutdown_triggers_size = 0;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    __tokens_with_ref_count_size = 1;
    __tokens_with_ref_count = (token_present_t*)malloc(1 * sizeof(token_present_t));
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 1;
    __is_present_fields = (bool**)malloc(1 * sizeof(bool*));
    // ************* Instance DelayArray of class DelayArray
    delayarray_self_t* delayarray_self = new_DelayArray();
    //***** Start initializing DelayArray
    // ************* Instance DelayArray.s of class Source
    source_self_t* delayarray_s_self = new_Source();
    //***** Start initializing DelayArray.s
    // Reaction 0 of DelayArray.s triggers 1 downstream reactions through port DelayArray.s.out.
    delayarray_s_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of DelayArray.s, allocate an
    // array of trigger pointers for downstream reactions through port DelayArray.s.out
    trigger_t** delayarray_s_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delayarray_s_self->___reaction_0.triggers[0] = delayarray_s_0_0;
    delayarray_s_self->___startup.offset = 0;
    delayarray_s_self->___startup.period = 0;
    __timer_triggers[0] = &delayarray_s_self->___startup;
    delayarray_s_self->__out.num_destinations = 1;
    //***** End initializing DelayArray.s
    // ************* Instance DelayArray.p of class Print
    print_self_t* delayarray_p_self = new_Print();
    //***** Start initializing DelayArray.p
    delayarray_p_self->scale = 1; 
    //***** End initializing DelayArray.p
    //***** End initializing DelayArray
    // Populate arrays of trigger pointers.
    // Point to destination port DelayArray.p.in's trigger struct.
    delayarray_s_0_0[0] = &delayarray_p_self->___in;
    // doDeferredInitialize
    delayarray_p_self->__in = NULL;
    delayarray_s_self->__out.token = __create_token(sizeof(int));
    // Connect inputs and outputs for reactor DelayArray.
    // Connect DelayArray.s.out to input port DelayArray.p.in
    delayarray_p_self->__in = (print_in_t*)&delayarray_s_self->__out;
    // Connect inputs and outputs for reactor DelayArray.s.
    // END Connect inputs and outputs for reactor DelayArray.s.
    // Connect inputs and outputs for reactor DelayArray.p.
    // END Connect inputs and outputs for reactor DelayArray.p.
    // END Connect inputs and outputs for reactor DelayArray.
    __tokens_with_ref_count[0].token
            = &delayarray_p_self->__in->token;
    __tokens_with_ref_count[0].is_present
            = &delayarray_p_self->__in->is_present;
    __tokens_with_ref_count[0].reset_is_present = false;
    // Add port DelayArray.s.out to array of is_present fields.
    __is_present_fields[0] = &delayarray_s_self->__out.is_present;
    delayarray_s_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayarray_s_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delayarray_p_self->___reaction_0.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayarray_p_self->___reaction_0.index = 0x7fffffffffff0001LL;
}
void __start_timers() {
    
    for (int i = 0; i < __timer_triggers_size; i++) {
        __schedule(__timer_triggers[i], 0LL, NULL);
    }
}
void logical_time_complete(instant_t time) {
}
instant_t next_event_time(instant_t time) {
    return time;
}
bool __wrapup() {
    __start_time_step();  // To free memory allocated for actions.
    for (int i = 0; i < __shutdown_triggers_size; i++) {
        __schedule(__shutdown_triggers[i], 0LL, NULL);
    }
    // Return true if there are shutdown actions.
    return (__shutdown_triggers_size > 0);
}
void __termination() {}