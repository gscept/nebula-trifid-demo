function oncollision(eid, othereid)
	if getcategory(othereid) == "Player" then
		playerdeath(othereid)	
	end
end;