<!-- [![analytics](http://www.google-analytics.com/collect?v=1&t=pageview&_s=1&dl=https%3A%2F%2Fgithub.com%2FIITDBGroup%2Fgprom%2Fmain&_u=MAC~&cid=123456789&tid=UA-92255635-2)]()
[![Build Status](https://travis-ci.org/IITDBGroup/gprom.svg?branch=master)](https://travis-ci.org/IITDBGroup/gprom)
 -->

# PUG (Provenance Unification through Graphs)

**PUG** is a database middleware system (originated from [GProM](https://github.com/IITDBGroup/PUG)) for provenance support to multiple database backends such as Oracle and Postgres. Provenance explains produced data over database operations such that which tuple (row) in the data generated by a query is derived from which tuple in input data through which operation(s). Similarly, why-not provenance informs why and how tuples are missing in the produced data. 

The system captures both why and why-not provenance for first-order (FO) Datalog queries, i.e., negation but no recursion is allowed, to explain user's interests (expressed in existing or missing tuples). Datalog is a declarative logic programming language used for deductive databases and provenance is often expressed as derivation of rules. PUG use query *instrumetation* technique which rewrites the Datalog queries into SQL query and execute the SQL on database backends. To visualize such derivations for users, provenance graphs can be generated based on the result of SQL queries. 

More information about PUG as well as research behind it can be found at UCDBG [webpage](https://sites.google.com/view/ucdbg). 

<!-- GProM provides an interactive shell `gprom`, a C library `libgprom`, and a JDBC driver. -->

<!-- 
# Online Demos

* [Online Demo for PUG Provenance Graph Explorer](http://ec2-18-218-236-30.us-east-2.compute.amazonaws.com:5000/)
 -->

# Documentation (Wiki Links)

* [Installation guide](https://github.com/UCDBG/PUG/wiki/installation)
* [Tutorial](https://github.com/UCDBG/PUG/wiki/tutorial)
* [Docker containers](https://github.com/UCDBG/PUG/wiki/docker)
* [Provenance Graphs for Datalog](https://github.com/UCDBG/PUG/wiki/datalog_prov)

<!-- 
# Features

+ Flexible on-demand provenance capture and querying for SQL queries using language-level instrumentation, i.e., by running SQL queries.
+ Retroactive provenance capture for transactions using reenactment. Notably, our approach requires no changes to the transactional workload and underlying DBMS
+ Produce provenance graphs for Datalog queries that explain why (provenance) or why-not (missing answers) a tuple is in the result of a Datalog query
+ Heuristic and cost-based optimization for queries instrumented for provenance capture
+ Export of database provenance into the WWW PROV standard format
 -->