附录
--

### FAQ ###

本节提供 `hustmq` 常见问题的答案。

**Q** :  如何部署 `hustmq`？  
**A** :  参考 [这里](../../../../../quickstart_zh.md)。

**Q** :  如何配置 `hustmq ha`？  
**A** :  参考 [这里](../advanced/ha/nginx.md) 。

**Q** :  `hustmq ha` 如何配置 `worker_processes`？  
**A** :  `hustmq ha` **只能配置单个 `worker`**。

**Q** :  `hustmq ha` 如何禁用 `http basic authentication`？  
**A** :  参考 [这一节](../advanced/ha/nginx.md) 的末尾对常见问题的解答。

**Q** :  `hustmq ha` 如何使用 `long polling` 机制？  
**A** :  参考 [这里](../api/ha.md)。

**Q** :  `hustmq ha` 如何使用 `http push` 实现数据的流式推送？  
**A** :  参考 [这里](../api/ha.md)。

**Q** :  `hustmq ha` 如何保证队列数据的先进先出？  
**A** :  参考 [这一节](../advanced/ha/nginx.md) 关于 `queue_hash` 的配置。

[回首页](../index.md)