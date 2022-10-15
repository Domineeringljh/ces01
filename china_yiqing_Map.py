import json
from re import T
from readline import append_history_file
from pyecharts.charts import Map#导入地图包
from pyecharts.options import *#导入全局配置包
#打开文件，获取文件内容
f=open("/Users/hua/疫情.txt","r",encoding="UTF-8")
f_wenj=f.read()
#关闭文件
f.close()
#JSON数据转py数据
f_dict=json.loads(f_wenj)
#获取各省份名称及确诊人数
f_dict_shengf=f_dict['areaTree'][0]['children']
#将数据转化为列表（因为map包需要用列表绘图）
f_line=[]
for f_dict in f_dict_shengf:
    f_dict_shengf_name=f_dict['name']#省名
    f_dict_shengf_renshu=f_dict['total']['confirm']#确诊人数
    f_line.append((f_dict_shengf_name,f_dict_shengf_renshu))#集合成列表
#创建地图对象
map=Map()
#添加数据
map.add("中国各省确诊人数",f_line,"china")
#设置全局配置，定制分段视觉效果
map.set_global_opts(
    title_opts=TitleOpts(title="中国疫情数据"),
    visualmap_opts=VisualMapOpts(
        is_show=True,#是否显示
        is_piecewise=True,#是否分段
        pieces=[
            {"min":1,"max":99,"lable":"1-99人","color":"#B2DFEE"},
            {"min":99,"max":999,"lable":"99-999人","color":"#FA8072"},
            {"min":999,"max":9999,"lable":"999-9999人","color":"#FF0000"},
            {"min":9999,"max":999999,"lable":"1-99人","color":"#561213"},
            {"min":1000000,"lable":"1000000+人","color":"#000000"},
        ]
    )
)


#绘制图像
map.render()