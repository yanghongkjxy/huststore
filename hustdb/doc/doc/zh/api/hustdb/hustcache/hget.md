## hget ##

**接口:** `/hustcache/hget`

**方法:** `GET`

**参数:** 

*  **tb** （必选）  
*  **key** （必选）  

**使用范例A:**

    curl -i -X GET "http://localhost:8085/hustcache/hget?tb=test_table&key=test_key"

**结果范例A1:**

	HTTP/1.1 404 Not Found

**结果范例A2:**

	HTTP/1.1 200 OK
	Content-Length: 8
	Content-Type: text/plain

	test_val

[上一页](../hustcache.md)

[回首页](../../../index.md)