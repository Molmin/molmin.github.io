F12 打开开发者工具，在最上面选择 Console（控制台），然后进行下面的操作。

#### 导出：

直接在控制台输入下面代码，输出的内容即为导出内容

```
console.log('window.localStorage.setItem("cp6_player_id","'+window.localStorage.getItem("cp6_player_id")+'");');
```

#### 导入：

将导出内容直接输入控制台，回车后刷新页面。

例如下面是 wangmaohua 的账号

```
window.localStorage.setItem("cp6_player_id","51acef81-e03b-41c6-900d-5765217dfefb");
```

例如下面是 没嘘嘘的 尖栗 的远古小号

```
window.localStorage.setItem("cp6_player_id","f04b9031-2760-49fd-be28-4dfdcff7bc20");
```
