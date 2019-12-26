#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPSClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/Context.h"
#include "Poco/StreamCopier.h"
#include "Poco/Path.h"
#include "Poco/URI.h"

#include <iostream>
#include <sstream>
#include <string>


int main(int argc, char **argv) {
    Poco::URI uri("https://api.anz/cds-au/v1/banking/products");
    const Poco::Net::Context::Ptr context = new Poco::Net::Context(Poco::Net::Context::CLIENT_USE,
                                                                   "", "", "",
                                                                   Poco::Net::Context::VERIFY_NONE,
                                                                   9, false,
                                                                   "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
    Poco::Net::HTTPSClientSession session(uri.getHost(), uri.getPort(), context);

    std::string path(uri.getPathAndQuery());

    Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_GET, path, Poco::Net::HTTPMessage::HTTP_1_1);
    session.sendRequest(req);

    Poco::Net::HTTPResponse res;
    std::cout << res.getStatus() << " " << res.getReason() << std::endl;

    std::istream &is = session.receiveResponse(res);
    std::stringstream ss;
    Poco::StreamCopier::copyStream(is, ss);
    std::cout << ss.str() << std::endl;

    return 0;
}