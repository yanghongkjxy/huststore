## evget ##

**接口:** `/evget`

**方法:** `GET`

**参数:** 

*  **queue** （必选）  
*  **worker** （必选）  
*  **ack** （可选）

该接口和 [put](put.md) 相配合实现 `long polling` 机制。

**使用范例:**

    curl -i -X GET "http://localhost:8080/evget?queue=test_queue&worker=test_worker"

[上一页](../ha.md)

[回首页](../../index.md)