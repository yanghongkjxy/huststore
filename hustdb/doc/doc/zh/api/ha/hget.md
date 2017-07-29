## hget ##

**接口:** `/hget`

**方法:** `GET`

**参数:** 

*  **tb** （必选）  
*  **key** （必选）  

该接口是 `/hustdb/hget` 的代理接口，参数详情可参考 [这里](../hustdb/hustdb/hget.md) 。

**使用范例:**

    curl -i -X GET "http://localhost:8082/hget?tb=test_table&key=test_key"

[上一页](../ha.md)

[回首页](../../index.md)