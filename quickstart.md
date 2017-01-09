<h1 id="id_top">Quick Start</h1>

* [HustDB](#id_hustdb)  
* [HustDB HA](#id_hustdbha)  
* [HustMQ](#id_hustmq)  
* [HustMQ HA](#id_hustmqha)  

<h2 id="id_hustdb">HustDB</h2>

Install `hustdb`(need sudo, used for libsnappy, libevhtp, libevent2.0): 

    $ cd hustdb/db/server/make/linux/
    $ sh build.sh

Target path

* `hustdb/db/server/make/linux/hustdb`
* `hustdb/db/server/make/linux/hustdb.conf`

Start service

    $ cd hustdb/db/server/make/linux/
    $ export LD_LIBRARY_PATH=/opt/huststore/3rd/lib
    $ ./hustdb

Type in the below command to test:

    curl -i -X GET 'localhost:8085/status.html'

Infomation returned:

    HTTP/1.1 200 OK
	Content-Length: 3
	Content-Type: text/plain

	ok

The result shows that the servers work as expected.

For detailed deployment and configuration, please check:

* [hustdb configuration](hustdb/doc/doc/en/advanced/hustdb.md)

[Back to top](#id_top)

<h2 id="id_hustdbha">HustDB HA</h2>

First, install all the dependent common modules for `hustdb ha`:  

* [zlog-1.2.12](https://github.com/HardySimpson/zlog/releases)
* [libevent-2.0.22-stable](https://github.com/libevent/libevent/releases/download/release-2.0.22-stable/libevent-2.0.22-stable.tar.gz)
* [libevhtp-1.2.10](https://github.com/ellzey/libevhtp/releases)

Install `pcre`：

    sudo yum install -y pcre-devel

Build `libcurl`：

    $ cd third_party
    $ sh build_libcurl.sh

Open the configuration:  

    $ cd ../hustdb/ha/nginx/conf/
    $ vi nginx.json

**Replace `backends` to your real `hustdb` machine list, at list two machine are required:**

    {
        ......
        "proxy":
        {
            ......
            "backends": 
            [
                "192.168.1.101:9999", 
                "192.168.1.102:9999"
            ],
            ......
        }
    }

Execute `genconf.py` to generate `nginx.conf`:

    $ python genconf.py

Edit file `hosts`:  

    $ vi hosts

Add contents as below and save, **please replace to your real hustdb nodes**：

    192.168.1.101:9999
    192.168.1.102:9999

Execute command：

    python gen_table.py hosts hustdbtable.json

After finish configuration, install `ha` and `sync server`:  

    $ cd ..
    $ chmod a+x configure
    $ sh Config.sh
    $ make -j
    $ make install
    $ cd ../../sync
    $ make -j
    $ make install

Start `HA` and `sync server` **in order**:

    $ export LD_LIBRARY_PATH=/opt/huststore/3rd/lib
    $ /opt/huststore/hustdbha/sbin/nginx
    $ cd /opt/huststore/hustdbsync
    $ /opt/huststore/hustdbsync/hustdbsync

Type in commands:

    curl -i -X GET 'localhost:8082/version'

We should be able to see the below infomation:

    HTTP/1.1 200 OK
    Server: nginx/1.10.0
    Date: Fri, 16 Dec 2016 10:56:55 GMT
    Content-Type: text/plain
    Content-Length: 13
    Connection: keep-alive

    hustdbha 1.6

The result shows that the servers work as expected.

For detailed deployment and configuration, please check:

* [hustdb ha deployment](hustdb/doc/doc/en/advanced/ha/deploy.md)
* [hustdb ha configuration](hustdb/doc/doc/en/advanced/ha/nginx.md)
* [hustdb ha load balance table configuration](hustdb/doc/doc/en/advanced/ha/table.md)
* [hustdb ha log configuration](hustdb/doc/doc/en/advanced/ha/zlog.md)

[Back to top](#id_top)

<h2 id="id_hustmq">HustMQ</h2>

Install `hustdb`(need sudo, used for libsnappy, libevhtp, libevent2.0): 

    $ cd hustdb/db/server/make/linux/
    $ sh build.sh

Target path

* `hustdb/db/server/make/linux/hustdb`
* `hustdb/db/server/make/linux/hustdb.conf`

Start service

    $ cd hustdb/db/server/make/linux/
    $ ./hustdb

Type in the below command to test:

    curl -i -X GET 'localhost:8085/status.html'

Infomation returned:

    HTTP/1.1 200 OK
	Content-Length: 3
	Content-Type: text/plain

	ok

The result shows that the servers work as expected.

For detailed deployment and configuration, please check:

* [hustmq configuration](hustmq/doc/doc/en/advanced/hustmq/index.md)

[Back to top](#id_top)

<h2 id="id_hustmqha">HustMQ HA</h2>

Install `pcre`：

    sudo yum install -y pcre-devel

Open the configuration:  

    $ cd hustmq/ha/nginx/conf/
    $ vi nginx.json

**Replace `backends` to your real `hustdb` machine list, at least one is required:**

    {
        ......
        "proxy":
        {
            ......
            "backends": ["192.168.1.101:9999"],
            ......
        }
    }

Run `genconf.py` to generate `nginx.conf`:

    $ python genconf.py

After configuration, install `hustmq ha`:

    $ cd hustmq/ha/nginx
    $ sh Config.sh
    $ make -j
    $ make install

Start nginx:

    $ export LD_LIBRARY_PATH=/opt/huststore/3rd/lib
    $ /opt/huststore/hustmqha/sbin/nginx

Input the following test command:

    curl -i -X GET 'localhost:8080/version'

Then server will output the following information:

    HTTP/1.1 200 OK
    Server: nginx/1.10.0
    Date: Fri, 16 Dec 2016 10:54:47 GMT
    Content-Type: text/plain
    Content-Length: 13
    Connection: keep-alive

    hustmqha 1.6

Server works just fine if the above result is returned.

For detailed deployment and configuration, please check:

* [hustmq ha configuration](hustmq/doc/doc/en/advanced/ha/nginx.md)
* [hustmq ha deployment](hustmq/doc/doc/en/advanced/ha/deploy.md)

[Back to top](#id_top)