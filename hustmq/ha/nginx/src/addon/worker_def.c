/**
******************************************************************************
* NOTE : Generated by jsoncgen. It is NOT supposed to modify this file.
*****************************************************************************/
#include "worker_def.h"

void cjson_dispose_hustmqworker(HustmqWorker * obj_val)
{
    if (obj_val)
    {
        cjson_dispose_string(&obj_val->w);
        cjson_dispose_integer(&obj_val->t);
    }
}

json_bool_t cjson_deserialize_hustmqworker(const json_t * json_val, HustmqWorker * obj_val)
{
    if (!obj_val || !json_is_object(json_val))
    {
        return false;
    }

    json_t * tmp_json_val = NULL;
    do
    {
        tmp_json_val = json_object_get_field(json_val, "w");
        obj_val->json_has_w = !!tmp_json_val;
        if (tmp_json_val && !cjson_deserialize_string(tmp_json_val, &obj_val->w)) break;
        tmp_json_val = json_object_get_field(json_val, "t");
        obj_val->json_has_t = !!tmp_json_val;
        if (tmp_json_val && !cjson_deserialize_integer(tmp_json_val, &obj_val->t)) break;

        return true;
    } while (0);

    return false;
}

json_bool_t cjson_load_hustmqworker(const char * input, HustmqWorker * obj_val)
{
    json_t * json_val = json_load_from_str(input);
    if (!json_val)
    {
        return false;
    }
    json_bool_t result = cjson_deserialize_hustmqworker(json_val, obj_val);
    cjson_dispose_json_value(json_val);
    return result;
}

void cjson_dispose_hustmqworkerarray(HustmqWorkerArray * obj_val)
{
    if (!obj_val || !obj_val->arr)
    {
        return;
    }
    size_t index;
    for (index = 0; index < obj_val->size; ++index)
    {
        cjson_dispose_hustmqworker(&obj_val->arr[index]);
    }
    json_free(obj_val->arr);
    obj_val->arr = NULL;
    obj_val->size = 0;
}

json_bool_t cjson_deserialize_hustmqworkerarray(const json_t * json_val, HustmqWorkerArray * obj_val)
{
    if (!json_is_array(json_val) || !obj_val)
    {
        return false;
    }
    obj_val->size = json_array_size(json_val);
    if (obj_val->size < 1)
    {
        obj_val->arr = NULL;
        return true;
    }
    obj_val->arr = json_malloc(sizeof(HustmqWorker) * obj_val->size);
    memset(obj_val->arr, 0, sizeof(HustmqWorker) * obj_val->size);
    size_t index;
    for (index = 0; index < obj_val->size; ++index)
    {
        json_t * tmp_json_val = json_array_get_item(json_val, index);
        if (!cjson_deserialize_hustmqworker(tmp_json_val, &obj_val->arr[index]))
        {
            cjson_dispose_hustmqworkerarray(obj_val);
            return false;
        }
    }
    return true;
}

json_bool_t cjson_load_hustmqworkerarray(const char * input, HustmqWorkerArray * obj_val)
{
    json_t * json_val = json_load_from_str(input);
    if (!json_val)
    {
        return false;
    }
    json_bool_t result = cjson_deserialize_hustmqworkerarray(json_val, obj_val);
    cjson_dispose_json_value(json_val);
    return result;
}
