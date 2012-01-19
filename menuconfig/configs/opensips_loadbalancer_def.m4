divert(-1)
define(`ENABLE_TCP', `yes') # OpenSIPS will listen on TCP for SIP requests
define(`ENABLE_TLS', `no') # OpenSIPS will listen on TLS for SIP requests
define(`USE_DBACC', `yes') # OpenSIPS will save ACC entries in DB for all calls
define(`USE_DISPATCHER', `yes') # OpenSIPS will use DISPATCHER instead of Load-Balancer for distributing the traffic
define(`DISABLE_PINGING', `no') # OpenSIPS will not ping at all the destinations (otherwise it will ping when detected as failed)
divert