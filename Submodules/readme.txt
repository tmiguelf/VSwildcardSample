This is where we would put other projects we depend on.
 1. There can be many git submodules here.
 2. Each git submodule has depedencies on other submodules.
 3. Dependency between submodules can be quite complex but never circular. Exemplified in following graph

Tier         This Repo
              / \  \
2            D   E  \
            / \ / \  \
1          B   C   \  \
          /         \  \
0        A           A  A

Note: Same letter = Same submodule


Graphs can get more complicated but higher tiers can only depend on strictly lower tiers.
Each submodule is its own autonomous project capable of living on its own.

Managing depedencies can be quite complicated. Allot of what you see here has been put in place to address issues with this setup.

For simplicity sake and demonstration purposes, these submodules are not real, but on a real system they would be.
