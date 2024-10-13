import scrapy
from ..items import Article

class FullDescriptionClass(scrapy.Spider):
    name='aajtak_fd'
    # start_urls=[
    #     'https://typos.com.cy/den-anamenontai-na-fthasoun-entos-tis-e/'
    # ]
    def __init__(self, url=None, *args, **kwargs):
          self.url=url
          super().__init__(url, *args, **kwargs)

    def start_requests(self):
          yield scrapy.Request(url=self.url, callback=self.parse)
    def parse(self,response):
        
            items_fd= Article()
            fd="".join(response.xpath('//div[@class="entry-content entry clearfix"]/p//span/text()').getall())
            items_fd['url']=self.url;
            items_fd['full_description']=fd
            yield items_fd
                                                                                                                                                                                                                        