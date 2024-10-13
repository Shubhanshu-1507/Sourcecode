from scrapy.crawler import CrawlerProcess
from scrapy.utils.project import get_project_settings
from scrapy import spiderloader

# Create a CrawlerProcess object with the settings for your Scrapy project
def feed():
    process= CrawlerProcess(get_project_settings())
    spider_cls= 'aajtak'
    process.crawl(spider_cls)
    process.start()
feed()

def full_description(spider, url):
    try:
        project_setting=get_project_settings()
        spider_loader= spiderloader.SpiderLoader.from_settings(project_setting)
        process= CrawlerProcess(get_project_settings())
        spider_cls=spider
        process.crawl(spider_cls, url=url)
        process.start()
    except Exception as e:
        print("Excetion occurs in process crawler", str(e))