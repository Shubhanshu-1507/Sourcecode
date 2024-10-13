# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class Feeds(scrapy.Item):
    # define the fields for your item here like:
    title = scrapy.Field()
    link= scrapy.Field()
    description=scrapy.Field()   
    pubDate=scrapy.Field()
    pass
class Article(scrapy.Item):
    url=scrapy.Field()
    full_description=scrapy.Field()
    pass

