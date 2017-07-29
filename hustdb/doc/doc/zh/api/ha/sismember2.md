## sismember2 ##

**接口:** `/sismember2`

**方法:** `POST`

**参数:** 

*  **tb** （必选）  
*  **key** （必选）  
该参数必须放在 `http body` 中

该接口是 `/hustdb/sismember` 的代理接口，参数详情可参考 [这里](../hustdb/hustdb/sismember.md) 。

**使用范例:**

    curl -i -X POST "http://localhost:8082/sismember2?tb=test_table" -d "test_key"

根据数据的版本的一致性的情况，该接口的返回一共有如下几种：

**返回范例1（版本一致）:**

    HTTP/1.1 200 OK
    Server: nginx/1.12.0
    Date: Tue, 18 Apr 2017 10:31:13 GMT
    Content-Type: text/plain
    Content-Length: 2
    Connection: keep-alive
    Version: 1

相关字段：
  
* `Version` ：值的版本号。

**返回范例2（版本不一致）:**

    HTTP/1.1 409 Conflict
    Server: nginx/1.12.0
    Date: Tue, 18 Apr 2017 10:33:09 GMT
    Content-Type: text/plain
    Content-Length: 5
    Connection: keep-alive
    Version1: 1
    Version2: 1

相关字段：

* `Version1`：`master1` 的值的版本号。  
* `Version2`：`master2` 的值的版本号。

[上一页](../ha.md)

[回首页](../../index.md)