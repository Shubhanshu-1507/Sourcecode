import scrapy
from ..items import Feeds

class QoutesSpider(scrapy.Spider):
    name='aajtak'
    start_urls=[
        'https://www.aajtak.in/rssfeeds?id=home'
    ]
    custom_settings={'COLLECTION_NAME':'abc'}
    def parse(self, response):
            list_i=response.xpath("//channel/item")
            items= Feeds()
            for item in list_i:
                items['title']=" ".join(item.xpath("title/text()").extract())
                items['link']=" ".join(item.xpath("link/text()").extract())
                items['description']=" ".join(item.xpath("description/text()").extract())
                items['pubDate']=" ".join(item.xpath("pubDate/text()").extract())
                yield items
