# Define your item pipelines here
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html
# useful for handling different item types with a single interface

from itemadapter import ItemAdapter
import pymongo
from .process_crawler import full_description
class ScrapperPipeline:
    def __init__(self):
        self.conn= pymongo.MongoClient(
            'localhost',
            27017
        )
        db= self.conn['NewTAk']
        self.collection=db['aajtak_full']
    def process_item(self, item, spider):
        item=dict(item)
        if len(item)>2:
            link=item['link']
            title=item['title']
            pubDate=item['pubDate']
            description=item['description']
            data={"link":link,"title":title,"pubDate":pubDate, "description":description}
    
            self.collection.insert_one(data)
            full_description(spider='aajtak_fd', url= data['link'])
    
        if len(item)==2:
            try:
                full_des= item['full_description']
                url= item['url']
                self.collection.update_one({'link':url},{'$set':{'full_description':full_des}})
            except Exception as e:
                print("Error in fd", str(e))
