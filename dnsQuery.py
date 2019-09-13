import dns.resolver

def get_domain_dns(domain):
        
        dns_records = list()

        try:
            # get the dns resolutions for this domain
            dns_results = dns.resolver.query(domain)
            dns_records = [ip.address for ip in dns_results]
        except dns.resolver.NXDOMAIN as e:
            # the domain does not exist so dns resolutions remain empty
            pass
        except dns.resolver.NoAnswer as e:
            # the resolver is not answering so dns resolutions remain empty
            pass

        return dns_records 
        
print(get_domain_dns('www.bacan.com.ar'))
