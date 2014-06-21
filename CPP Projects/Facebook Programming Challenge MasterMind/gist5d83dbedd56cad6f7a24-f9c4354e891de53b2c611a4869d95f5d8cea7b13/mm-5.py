import fileinput, itertools

class MasterMind:
    def __chkPairs(node):
        PG = node.__GS[0]
        for gss in reversed(node.__GS):
            if gss[len(gss) - 1] < (node.__GL / 2):
                return True
            SE = 0
            for PS in xrange(0, node.__GL):
                if gss[PS] == PG[PS]:
                    SE += 1
            if SE < (gss[len(gss) - 1] - (node.__GL / 2)):
                return False
        return True

    def __crKeys(node, Q_max):
        pb = {}
        npb = {}
        KM = {}
        for PS in xrange(0, node.__GL):
            pb[PS] = set()
            npb[PS] = set()
        for gss in Q_max:
            RS = gss[len(gss) - 1]
            TNP = 0
            for PS in xrange(0, node.__GL):
                if gss[PS] in npb[PS]:
                    TNP += 1
            if (node.__GL - TNP) == RS:
                for PS in xrange(0, node.__GL):
                    if gss[PS] not in npb[PS]:
                        KM[PS] = gss[PS]
            else:
                for PS, value in KM.items():
                    if gss[PS] == value:
                        RS -= 1
                    else:
                        RS += 1
                if RS == 0:
                    for PS in xrange(0, node.__GL):
                        npb[PS].add(gss[PS])
                        pb[PS].discard(gss[PS])
                else:
                    for PS in xrange(0, node.__GL):
                        if (node.__GL - PS) == RS:
                            if PS not in KM:
                                KM[PS] = gss[PS]
                            RS -= 1
                        else:
                            if gss[PS] not in npb[PS]:
                                RS -= 1
                                pb[PS].add(gss[PS])
        MK = []
        if len(pb) > 0:
            for PS in xrange(0, node.__GL):
                if PS in KM:
                    MK.append([KM[PS]])
                else:
                    if len(pb[PS]) == 0:
                        keys = []
                        for cnt in xrange(1, node.__N_max + 1):
                            if cnt not in npb[PS]:
                                keys.append(cnt)
                        MK.append(keys)
                    else:
                        MK.append(list(pb[PS]))
        PKV = []
        for PS in xrange(0, node.__GL):
            if PS in KM:
                PKV.append([KM[PS]])
            else:
                keys = []
                for cnt in xrange(1, node.__N_max + 1):
                    if cnt not in npb[PS]:
                        keys.append(cnt)

                PKV.append(keys)                        
        return MK, PKV

    def __chkGuess(node, IK):
        for gss in node.__GS:
            scr = 0
            for PS in xrange(0, node.__GL):
                if IK[PS] == gss[PS]:
                    scr += 1
            if scr < gss[len(gss) - 1]:
                return False
        return True

    def resolve(node):
        node.__GS = sorted(node.__GS, key = lambda gss: gss[len(gss) - 1])
        if not node.__chkPairs():
            return "No"
        MK, PK = node.__crKeys(node.__GS)
        for key in itertools.product(*MK):
            if node.__chkGuess(key):
                return "Yes"
        for key in itertools.product(*PK):
            if node.__chkGuess(key):
                return "Yes"
        return "No"

    def __init__(node, N_max, K_max, Q_max):
        node.__N_max = N_max
        node.__GS = Q_max
        node.__GL = K_max

if __name__ == "__main__":
    lines = [line.replace('\n', '') for line in fileinput.input()]
    CL = 1
    for PL in xrange(0, int(lines[0])):
        PI = map(int, lines[CL].split())
        GS = []
        for gss in xrange(0, PI[2]):
            CL += 1
            GS.append(map(int, lines[CL].split()))
        print MasterMind(PI[0], PI[1], GS).resolve()
        CL += 1