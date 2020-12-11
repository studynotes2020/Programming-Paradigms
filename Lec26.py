from urllib import urlopen
from xml.sax import make_parser, ContentHandler
import sys

# To handle content of xml file
class ContentHandler:
    def __init__(self):
        pass

    def startElement(self, tag, attrs):
        pass

    def endElement(self, tag):
        pass

    def characters(self, data):
        pass

# Inherit from ContentHandler to resue the methods
class RSSHandler(ContentHandler):
    def __init__(self):
        ContentHandler.__init__(self)  # initialize superclass
        self.__inItem = False
        self.__inTitle = False

    def characters(self, data):
        if self.__inTitle:
            sys.stdout.write(data)

    def startElement(self, tag, attrs):
        if tag == 'item':
            self.__inItem = True
        if tag == "title" and self.__inItem:
            self.__inTitle = True

    def endElement(self, tag):
        if tag == "title" and self.__inTitle:
            sys.stdout.write("\n")
            self.__inTitle = False
        if tag == "item":
            self.__inItem = False
            


def listFeedTitles(url):
    infile = urlopen(url)
    parser = make_parser()
    parser.setContentHandler(RSSHandler())
    parser.parse(infile)


