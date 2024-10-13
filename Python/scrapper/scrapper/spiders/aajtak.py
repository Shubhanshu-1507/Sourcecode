import scrapy
# from ..items import ScrapperItem

class QoutesSpider(scrapy.Spider):
    name='aaj'
    start_urls=[
        'https://www.aajtak.in/rssfeeds?id=home'
    ]
    custom_settings={'COLLECTION_NAME':'abc'}
    def parse(self, response):
            list_i=response.xpath("//channel/item")
            # items= ScrapperItem()
            # for item in list_i:
            #     items['title']=" ".join(item.xpath("title/text()").extract())
            #     items['link']=" ".join(item.xpath("link/text()").extract())
            #     items['description']=" ".join(item.xpath("description/text()").extract())
            #     items['pubDate']=" ".join(item.xpath("pubDate/text()").extract())
            #     yield items
            for item in list_i:
                 title=item.xpath("title/text()").get()
                 link=item.xpath("link/text()").get()
                 description= item.xpath("description/text()").get()
                 pubDate=item.xpath("pubDate/text()").get()
                 for i in link:
                    yield scrapy.Request(url=link, callback=self.parse_fullDesription, meta={'title':title,'link':link,'description':description, 'pubDate':pubDate})
    def parse_fullDesription(self, response):
        title = response.request.meta['title']
        link = response.request.meta['link']
        description = response.request.meta['description']
        pubDate = response.request.meta['pubDate']
    
        full_description = response.xpath("//div[@class='story-with-main-sec']/div/p")
        yield {
                'title': title,
                'link':link,
                'description':description,
                'pubDate':pubDate,
                'full_description':full_description
                }                                                                                                                                                                                                             